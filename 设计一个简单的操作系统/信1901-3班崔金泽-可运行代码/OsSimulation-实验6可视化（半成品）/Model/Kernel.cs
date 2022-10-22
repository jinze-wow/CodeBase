using Prism.Mvvm;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Threading;
using System.Windows.Threading;
using static OS.Model.Constants;
using static OS.Model.OuterMemoryModel;
using static OS.Model.ProcessModel;
using static OS.Model.ProcessModel.CodeSegment;
using Condition = OS.Model.PhysicalMemoryModel.Condition;

namespace OS.Model
{
    /// <summary>
    /// os kernel manages everything
    /// </summary>
    internal class Kernel : BindableBase
    {
        #region Var
        
        /// <summary>
        /// hardware simulation references
        /// </summary>
        #region Hardware

        private CpuModel _cpu;
        private PhysicalMemoryModel _innerMemory;
        private OuterMemoryModel _outerMemory;

        #endregion Hardware

        /// <summary>
        /// data structures for process scheduling
        /// </summary>
        #region Process

        private ObservableCollection<PCB> _pcbTable;
        private ObservableCollection<PCB> _readyList;
        private ObservableCollection<PCB> _blockList;
        private PCB _runningPcb;

        private Queue<PCB> _reserveQueue;

        #endregion Process

        /// <summary>
        /// multithread programming
        /// </summary>
        #region Threads

        private Thread _createJobs;
        private Thread _scheduleThread;
        private Thread _inputJobsThread;
        private Thread _runInsThread;

        private ManualResetEvent _createReset = new ManualResetEvent(true);
        private ManualResetEvent _scheduleReset = new ManualResetEvent(true);
        private ManualResetEvent _inputReset = new ManualResetEvent(true);
        private ManualResetEvent _runReset = new ManualResetEvent(true);

        #endregion Threads

        #region other

        string _log;

        #endregion

        #endregion Var

        #region Property

        public PCB Running
        {
            get => _runningPcb;
            set => SetProperty(ref _runningPcb, value);
        }

        public ObservableCollection<PCB> ReadyList
        {
            get => _readyList;
            set => SetProperty(ref _readyList, value);
        }

        public ObservableCollection<PCB> BlockList
        {
            get => _blockList;
            set => SetProperty(ref _blockList, value);
        }

        public ObservableCollection<PCB> ReserveQueue
        {
            get => new ObservableCollection<PCB>(_reserveQueue.ToList<PCB>());
            set => SetProperty(ref _reserveQueue, new Queue<PCB>(value.ToList()));
        }

        public CpuModel Cpu
        {
            get => _cpu;
            set => SetProperty(ref _cpu, value);
        }

        public long Time
        {
            get => Cpu.Clock.Counter;
        }

        public ObservableCollection<Condition> Memory
        {
            get => new ObservableCollection<Condition>(_innerMemory.AlloMap);
        }

        public ObservableCollection<Sector> Disk
        {
            get => _outerMemory.Collection;
        }

        public string Log {
            get => _log;
            set => SetProperty(ref _log, value);
        }


        #endregion Property

        #region Methods

        #region Process Manager

        /// <summary>
        /// main function to schedule threads
        /// </summary>
        private void ScheduleThread()
        {
            while (true)
            {
                _scheduleReset.WaitOne();
                Record("Schedule start");
                _cpu.CpuMode = CpuModes.system;

                var arr = new List<PCB>(_blockList).ToArray();
                foreach (PCB pcb in arr)
                {
                    if (pcb.RemainingBlockTime-- <= 0)
                    {
                        WakeProcess(pcb);
                        if (_blockList.Count == 0)
                            break;
                    }
                }

                //if dont exist a running process or the running process is up to timeslice
                //choose one in ready list to run
                if (_runningPcb == null || (_runningPcb.RunTime % TimeSlice == 0 && _runningPcb.RunTime != 0))
                {
                    if (_readyList.Count != 0)
                    {
                        //choose suitable process to run
                        PCB process2run = FindMaxPriPCB();
                        Record($"running pcb switched to {process2run.Pid} ");
                        SynchronizationContext.SetSynchronizationContext(new
    DispatcherSynchronizationContext(System.Windows.Application.Current.Dispatcher));
                        SynchronizationContext.Current.Post(pl =>
                        {
                            if (Running != null)
                            {
                                Running.State = PCB.States.ready;
                                ReadyList.Add(Running);
                            }
                            process2run.State = PCB.States.running;
                            Running = process2run;
                            _cpu.mmu.PageTable = Running.pageTable;
                            ReadyList.Remove(process2run);
                        }, null);
                    }
                    else
                    {
                        Record($"process keeps runnning");
                        goto SchduleSleep;
                    }
                }

                SchduleSleep:
                _cpu.CpuMode = CpuModes.user;
                Record("Schdule End");

                Thread.Sleep(_cpu.Clock.TimeSpan);
            }
        }

        #region System Call

        /// <summary>
        /// create process with a pcb
        /// </summary>
        /// <param name="pcb"></param>
        public void CreateProcess(PCB pcb)
        {
            RaisePropertyChanged("ReserveQueue");
            Code2Swap(pcb);
            _pcbTable.Add(pcb);
            ThreadPool.QueueUserWorkItem(delegate
            {
                SynchronizationContext.SetSynchronizationContext(new
                    DispatcherSynchronizationContext(System.Windows.Application.Current.Dispatcher));
                SynchronizationContext.Current.Post(pl =>
                {
                    ReadyList.Add(pcb);
                }, null);
            });
            Record($"Process {pcb.Pid} created");
        }


        /// <summary>
        /// wake process with a pcb reference
        /// </summary>
        /// <param name="pcb"></param>
        public void WakeProcess(PCB pcb)
        {
            pcb.State = PCB.States.ready;
            ThreadPool.QueueUserWorkItem(delegate
            {
                SynchronizationContext.SetSynchronizationContext(new
                    DispatcherSynchronizationContext(System.Windows.Application.Current.Dispatcher));
                SynchronizationContext.Current.Post(pl =>
                {
                    ReadyList.Add(pcb);
                    BlockList.Remove(pcb);
                }, null);
            });
        }


        /// <summary>
        /// block process due to system call or so on
        /// no params taken, block random seconds
        /// </summary>
        public void BlockProcess()
        {
            ThreadPool.QueueUserWorkItem(delegate
            {
                SynchronizationContext.SetSynchronizationContext(new
                    DispatcherSynchronizationContext(System.Windows.Application.Current.Dispatcher));
                SynchronizationContext.Current.Post(pl =>
                {
                    Running.State = PCB.States.blocked;
                    Running.RemainingBlockTime = new Random().Next(BlockTimeMin, BlockTimeMax);
                    BlockList.Add(_runningPcb);
                    Running = null;
                }, null);
            });
        }

        /// <summary>
        /// block process due to system call or so on
        /// block seconds according to param
        /// </summary>
        /// <param name="seconds"></param>
        public void BlockProcess(int seconds)
        {
            ThreadPool.QueueUserWorkItem(delegate
            {
                SynchronizationContext.SetSynchronizationContext(new
                    DispatcherSynchronizationContext(System.Windows.Application.Current.Dispatcher));
                SynchronizationContext.Current.Post(pl =>
                {
                    Running.State = PCB.States.blocked;
                    Running.RemainingBlockTime = seconds;
                    BlockList.Add(_runningPcb);
                    Running = null;
                }, null);
            });
        }


        /// <summary>
        /// cancle process with the reference pcb
        /// </summary>
        /// <param name="pcb"></param>
        public void CancelProcess(ref PCB pcb)
        {
            foreach (var entry in pcb.externalPageTable.PageEntries)
            {
                _outerMemory.GetSector(entry.BlockNumber).Occupied = false;
            }
            foreach (var entry in pcb.pageTable.Entries)
            {
                if (entry.Present)
                    _innerMemory.AlloMap[entry.FrameNo].Occupied = false;
            }
            _innerMemory.AlloMap[pcb.pageTableFrameIndex].Occupied = false;
            pcb = null;
        }

        #endregion System Call

        /// <summary>
        /// continuously create random processes
        /// </summary>
        private void RandomCreateProcess()
        {
            while (true)
            {
                _createReset.WaitOne();
                CreateJob();
                Thread.Sleep(new Random().Next(CreateJobMin, CreateJobMax) * _cpu.Clock.TimeSpan);
            }
        }

        /// <summary>
        /// simualtion of the kernel handling the system call from user process
        /// </summary>
        private void AcceptCall()
        {
            _cpu.CpuMode = CpuModes.system;
            BlockProcess();
            _cpu.CpuMode = CpuModes.user;
        }


        /// <summary>
        /// run instructions
        /// </summary>
        /// <param name="pcb"></param>
        private void RunInstruction(PCB pcb)
        {
            var ins = pcb.CodeSegment.Instructions[pcb.PC];
            Record($"ins {pcb.PC} running");
            pcb.RunTime++;
            var physicalAddr = Logical2Physical(pcb, new Address((ushort)pcb.CodeAddress));

            //if Page fault occurs, instantly return
            //this instruction will run in next execution
            if (physicalAddr == null)
                return;

            switch (ins.InsType)
            {
                case InstructionTypes.Calculate:
                    DoSomething();
                    break;

                case InstructionTypes.ReadMemory:
                    var readAddr = Logical2Physical(pcb, ins.Addr);
                    if (readAddr == null) return;
                    pcb.pageTable.Entries[ins.Addr.PageIndex].Referred = true;
                    DoSomething();
                    break;

                case InstructionTypes.WriteMemory:
                    var writeAddr = Logical2Physical(pcb, ins.Addr);
                    if (writeAddr == null) return;
                    pcb.pageTable.Entries[ins.Addr.PageIndex].Modified = true;
                    DoSomething();
                    break;

                case InstructionTypes.SystemCall:
                    AcceptCall();
                    break;

                case InstructionTypes.Return:
                    CancelProcess(ref pcb);
                    break;

                default:
                    break;
            }
            if (pcb != null)
                pcb.PC++;
        }


        /// <summary>
        /// empty function designed to simulate "do something"
        /// </summary>
        private void DoSomething()
        {
        }


        /// <summary>
        /// thread to run instructions
        /// </summary>
        private void RunInsThread()
        {
            while (true)
            {
                _runReset.WaitOne();
                if (_cpu.CpuMode == CpuModes.user)
                {
                    if (_runningPcb != null)
                        RunInstruction(_runningPcb);
                }

                Thread.Sleep(_cpu.Clock.TimeSpan);
            }
        }
        

        /// <summary>
        /// find the max priority pcb
        /// </summary>
        /// <returns></returns>
        private PCB FindMaxPriPCB()
        {
            int maxPri = 5;
            PCB maxPCB = _readyList[0];

#pragma warning disable CS0618
            _inputJobsThread.Suspend();
            foreach (PCB pcb in _readyList.ToArray())
            {
                if (pcb.Priority <= maxPri)
                {
                    maxPri = pcb.Priority;
                    maxPCB = pcb;
                }
            }
            _inputJobsThread.Resume();
#pragma warning restore CS0618

            return maxPCB;
        }

        #endregion Process Manager

        #region Job Manager

        /// <summary>
        /// convert jcb to pcb
        /// </summary>
        /// <param name="jcb"></param>
        /// <returns></returns>
        public PCB Job2Process(JCB jcb)
        {
            CodeSegment code = new CodeSegment() { Instructions = jcb.Instructions };
            PCB pcb = new PCB
            {
                Priority = jcb.Priority,
                InsNum = jcb.InsNum,
                CodeSegment = code
            };
            ProcessModel p = new ProcessModel(pcb, code);

            return pcb;
        }


        /// <summary>
        /// thread to input reserved jobs 
        /// </summary>
        private void InputJobsThread()
        {
            while (true)
            {
                _inputReset.WaitOne();
                if (_reserveQueue.Count == 0)
                {
                    Record("no reserved jobs");
                    goto Sleep;
                }
                var freeFrame = _innerMemory.FreePageTable;
                //check if have enough swap space for process
                if (_outerMemory.EmptySwapBlock >= _reserveQueue.Peek().CodeSegment.CodeBlocks && freeFrame != null)
                {
                    _reserveQueue.Peek().pageTableFrameIndex = (int)freeFrame;
                    _innerMemory.AlloMap[(int)freeFrame].Occupied = true;
                    CreateProcess(_reserveQueue.Dequeue());
                }
                else
                {
                    Record("no enough swap area");
                }

                Sleep:
                Thread.Sleep(_cpu.Clock.TimeSpan);
            }
        }

        public void CreateJob()
        {
            Record("Create pcb start");
            JCB jcb = new JCB();
            PCB pcb = Job2Process(jcb);
            _reserveQueue.Enqueue(pcb);
            RaisePropertyChanged("ReserveQueue");
            Record("Create pcb end");
        }

        #endregion Job Manager

        #region Memory Manager


        /// <summary>
        /// convert logical address to physical address
        /// if found in mmu, return address
        /// if not found, raise page fault and wait for the program to run again
        /// </summary>
        /// <param name="pcb"></param>
        /// <param name="logicalAddr"></param>
        /// <returns></returns>
        public Address Logical2Physical(PCB pcb, Address logicalAddr)
        {
            _cpu.mmu.PageTable = pcb.pageTable;
            Address addr = _cpu.mmu.Logical2Physical(logicalAddr);
            if (addr != null)
            {
                return addr;
            }
            else
            {
                _cpu.CpuMode = CpuModes.system;
                PageFault(pcb, logicalAddr);
                _cpu.CpuMode = CpuModes.user;
                return null;
            }
        }

        /// <summary>
        /// raise page fault
        /// </summary>
        /// <param name="pcb"></param>
        /// <param name="logicalAddr"></param>
        public void PageFault(PCB pcb, Address logicalAddr)
        {
            Record("Page fault");

            //find block num in external page table
            var blockNum = pcb.externalPageTable.GetBlockNum(logicalAddr);
            if (blockNum != null)
            {
                var emptyFrame = GetEmptyFrame();
                //can't find an empty frame, replace one
                if (emptyFrame == null)
                {
                    //replace with LRU algorithm
                    int entry2replace = pcb.pageTable.Entry2Replace();

                    //if modified then write back to swap
                    if (pcb.pageTable.Entries[entry2replace].Modified)
                    {
                        emptyFrame = pcb.pageTable.Entries[entry2replace].FrameNo;
                        int block2write = (int)pcb.externalPageTable.GetBlockNum((ushort)entry2replace);
                        Memory2Swap((int)emptyFrame, block2write);
                        pcb.externalPageTable.PageEntries.Add(
                            new ExternalPageTable.ExternalPageEntry((ushort)entry2replace, (ushort)block2write)
                            );
                        pcb.pageTable.Entries[entry2replace].Present = false;
                        _innerMemory.AlloMap[(int)emptyFrame].Occupied = false;
                        RaisePropertyChanged("AlloMap");
                    }
                }

                //after all, there's an empty frame
                Swap2Memory((int)blockNum, (int)emptyFrame);
                var entry = pcb.pageTable.Entries[logicalAddr.PageIndex];
                entry.FrameNo = (ushort)emptyFrame;
                entry.Referred = true;
                entry.Present = true;
                //set the leftmost bit to 1
                entry.Register |= 0b1000;

                _innerMemory.AlloMap[(int)emptyFrame].Occupied = true;
                RaisePropertyChanged("AlloMap");
            }
            else
            {
                var frameNo = GetEmptyFrame();
                if (frameNo == null)
                {
                    BlockProcess(1);
                }
                else
                {
                    var entry = pcb.pageTable.Entries[logicalAddr.PageIndex];
                    entry.FrameNo = (ushort)frameNo;
                    entry.Referred = true;
                    entry.Present = true;
                    //set the leftmost bit to 1
                    entry.Register |= 0b1000;

                    _innerMemory.AlloMap[(int)frameNo].Occupied = true;
                }
            }
        }

        /// <summary>
        /// find an empty frame in RAM
        /// if found, return frame index
        /// if not, return null
        /// </summary>
        /// <returns></returns>
        private int? GetEmptyFrame()
        {
            for (int i = PageTableSplit; i < PhysicalFrameNum; i++)
            {
                if (_innerMemory.AlloMap[i].Occupied == false)
                {
                    return i;
                }
            }
            return null;
        }

        /// <summary>
        /// transfer data from swap area to RAM
        /// </summary>
        /// <param name="block"></param>
        /// <param name="frame"></param>
        private void Swap2Memory(int block, int frame)
        {
            var sector = _outerMemory.GetSector(block);
            var page = _innerMemory.Pages[frame];
            for (int i = 0; i < SectorSize; i += 2)
            {
                ushort data = (ushort)(sector.Data[i] << 8 + sector.Data[i + 1]);
                page.Data[i] = (byte)(data >> 8);
                page.Data[i + 1] = (byte)(data & 0xff);
            }
        }


        /// <summary>
        /// tranfer data from RAM to swap area
        /// </summary>
        /// <param name="frame"></param>
        /// <param name="block"></param>
        private void Memory2Swap(int frame, int block)
        {
            var page = _innerMemory.Pages[frame];
            var sector = _outerMemory.GetSector(block);

            for (int i = 0; i < SectorSize; i += 2)
            {
                ushort data = (ushort)(page.Data[i] << 8 + page.Data[i + 1]);
                sector.Data[i] = (byte)(data >> 8);
                sector.Data[i + 1] = (byte)(data & 0xff);
            }
        }

        /// <summary>
        /// transfer code segment to swap area
        /// </summary>
        /// <param name="pcb"></param>
        private void Code2Swap(PCB pcb)
        {
            int blocks = pcb.CodeSegment.CodeBlocks;
            for (int i = 0; i < blocks; i++)
            {
                int sectorIndex = _outerMemory.WriteInSwapSector();
                pcb.externalPageTable.PageEntries.Add(new ExternalPageTable.ExternalPageEntry((ushort)i, (ushort)sectorIndex));
            }
        }

        #endregion Memory Manager

        #region Threads Manager

        /// <summary>
        /// resume threads
        /// </summary>
        public void ResumeThreads()
        {
            _cpu.Clock.Start();
            _createReset.Set();
            _inputReset.Set();
            _runReset.Set();
            _scheduleReset.Set();
        }

        /// <summary>
        /// pause threads
        /// </summary>
        public void PauseThreads()
        {
            _cpu.Clock.Pause();
            _createReset.Reset();
            _inputReset.Reset();
            _runReset.Reset();
            _scheduleReset.Reset();
        }

        #endregion Threads Manager

        #region Initialization Manager

        /// <summary>
        /// load kernel into memory
        /// </summary>
        public void LoadInKernel()
        {
            for (int i = 0; i < KernelSplit; i++)
            {
                _innerMemory.AlloMap[i].Occupied = true;
            }
        }

        /// <summary>
        /// load jobs from outer files
        /// job info in "job.txt"
        /// instruction info for each job in "1.txt", "2.txt", ...
        /// </summary>
        public void LoadJobs()
        {
            int jobCounter = 1;

            //read jobs.txt
            using (StreamReader jobReader = new StreamReader("jobs.txt"))
            {
                jobReader.ReadLine();

                //read each line and generate job
                string job;
                char[] separator = { '\t', ' ' };
                while ((job = jobReader.ReadLine()) != null)
                {
                    string[] jobInfo = job.Split(separator, StringSplitOptions.RemoveEmptyEntries);
                    List<Instruction> instructions = new List<Instruction>();

                    //read detailed instructions
                    using (StreamReader insReader = new StreamReader(jobCounter.ToString() + ".txt"))
                    {
                        insReader.ReadLine();

                        string ins;
                        
                        for(int i = 0; i < int.Parse(jobInfo[1]); i++)
                        {
                            ins = insReader.ReadLine();
                            string[] insInfo = ins.Split(separator, StringSplitOptions.RemoveEmptyEntries);
                            Instruction instruction = new Instruction
                            {
                                InsId = i,
                                InsType = (InstructionTypes)int.Parse(insInfo[0]),
                                Addr = insInfo[1] == "null" ? null : new Address(ushort.Parse(insInfo[1]))
                            };
                            instructions.Add(instruction);
                        }
                    }

                    JCB jcb = new JCB(int.Parse(jobInfo[0]), int.Parse(jobInfo[1]), instructions);
                    PCB pcb = Job2Process(jcb);
                    _reserveQueue.Enqueue(pcb);
                    RaisePropertyChanged("ReserveQueue");
                    jobCounter++;
                }
            }
        }

        /// <summary>
        /// initialize hardwares
        /// </summary>
        public void InitializeHardwares()
        {
            _cpu = new CpuModel();
            _innerMemory = new PhysicalMemoryModel();
            _outerMemory = new OuterMemoryModel();
        }

        /// <summary>
        /// initialize data structures
        /// </summary>
        public void InitializeLists()
        {
            _pcbTable = new ObservableCollection<PCB>();
            _readyList = new ObservableCollection<PCB>();
            _blockList = new ObservableCollection<PCB>();
            _reserveQueue = new Queue<PCB>();
        }

        /// <summary>
        /// initialize threads;
        /// </summary>
        public void InitializeThreads()
        {
            LoadJobs();

            _createJobs = new Thread(new ThreadStart(RandomCreateProcess));
            _scheduleThread = new Thread(new ThreadStart(ScheduleThread));
            _inputJobsThread = new Thread(new ThreadStart(InputJobsThread));
            _runInsThread = new Thread(new ThreadStart(RunInsThread));

            _createJobs.Priority = ThreadPriority.Highest;
            _inputJobsThread.Priority = ThreadPriority.AboveNormal;
            _scheduleThread.Priority = ThreadPriority.Normal;
            _runInsThread.Priority = ThreadPriority.BelowNormal;

            Cpu.Clock.Timer.Tick += (s, e) => { Cpu.Clock.Counter++; RaisePropertyChanged("Time"); };
            Cpu.Clock.Timer.Start();
            //_createJobs.Start();
            _inputJobsThread.Start();
            _runInsThread.Start();
            _scheduleThread.Start();
        }

        #endregion Initialization Manager

        #region Other Methods

        /// <summary>
        /// output kernel info to console and GUI
        /// </summary>
        /// <param name="str"></param>
        void Record(string str)
        {
            Console.WriteLine(str);
            Log += str + '\n';
        }

        #endregion

        #endregion Methods

        #region Constructor

        public Kernel()
        {
        }

        #endregion Constructor
    }
}