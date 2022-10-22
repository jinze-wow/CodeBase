using Prism.Mvvm;
using System.Collections.Generic;
using static OS.Model.Constants;

namespace OS.Model
{
    /// <summary>
    /// simulation of process in OS
    /// </summary>
    internal class ProcessModel : BindableBase
    {
        #region inner class

        public class PCB : BindableBase
        {
            public enum States { ready, running, blocked };

            #region var

            private int _pid;
            private States _state;
            private int _priority;
            private int _insNum;
            private int _pc;
            private int _runTime;
            private CodeSegment _codeSegment;
            private int _remainingBlockTime;
            private ProcessModel _processRef;

            public ExternalPageTable externalPageTable = new ExternalPageTable();
            public int pageTableFrameIndex;
            public PageTable pageTable = new PageTable();

            private static int _pidCounter = 0;

            #endregion var

            #region property

            public int Pid
            {
                get => _pid;
                set
                {
                    SetProperty(ref _pid, value);
                }
            }

            public States State
            {
                get => _state;
                set
                {
                    SetProperty(ref _state, value);
                }
            }

            public int Priority
            {
                get => _priority;
                set
                {
                    SetProperty(ref _priority, value);
                }
            }

            public int InsNum
            {
                get => _insNum;
                set
                {
                    SetProperty(ref _insNum, value);
                }
            }

            public int PC
            {
                get => _pc;
                set => SetProperty(ref _pc, value);
            }

            public CodeSegment CodeSegment
            {
                get => _codeSegment;
                set
                {
                    SetProperty(ref _codeSegment, value);
                }
            }

            public int RunTime
            {
                get => _runTime;
                set
                {
                    SetProperty(ref _runTime, value);
                }
            }

            public int CodeAddress
            {
                get => _pc * (LengthOfIns / Byte);
            }

            public static int PidCounter
            {
                get => _pidCounter;
                set => _pidCounter = value;
            }

            public int RemainingBlockTime
            {
                get => _remainingBlockTime;
                set
                {
                    SetProperty(ref _remainingBlockTime, value);
                }
            }

            public ProcessModel ProcessRef
            {
                get => _processRef;
                set => SetProperty(ref _processRef, value);
            }

            #endregion property

            #region Constructor

            public PCB()
            {
                Pid = _pidCounter++;
                State = States.ready;
                PC = 0;
            }

            #endregion Constructor
        }

        public class CodeSegment : BindableBase
        {
            public class Instruction
            {
                public int InsId { get; set; }
                public InstructionTypes InsType { get; set; }
                public Address Addr { get; set; }
            }

            private List<Instruction> _instructions;

            public CodeSegment()
            {
                _instructions = new List<Instruction>();
            }

            public List<Instruction> Instructions
            {
                get => _instructions;
                set => SetProperty(ref _instructions, value);
            }

            public int CodeBlocks { get => Instructions.Count / (BlockSize / (LengthOfIns / Byte)) + 1; }
        }

        #endregion inner class

        #region Var

        private PCB _pcb;
        private CodeSegment _codeSegment;

        #endregion Var

        #region Property

        public PCB Pcb
        {
            get => _pcb;
            set
            {
                SetProperty(ref _pcb, value);
            }
        }

        public CodeSegment CodeSegment_
        {
            get => _codeSegment;
            set
            {
                SetProperty(ref _codeSegment, value);
            }
        }

        #endregion Property

        #region Constructor

        public ProcessModel()
        {
            Pcb = new PCB
            {
                ProcessRef = this
            };
            CodeSegment_ = new CodeSegment();
        }

        public ProcessModel(PCB pcb, CodeSegment codeSegment)
        {
            Pcb = pcb;
            Pcb.ProcessRef = this;
            CodeSegment_ = codeSegment;
        }

        #endregion Constructor
    }
}