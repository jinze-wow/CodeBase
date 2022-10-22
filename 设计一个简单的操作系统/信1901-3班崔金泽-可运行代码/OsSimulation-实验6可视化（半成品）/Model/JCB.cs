using System;
using System.Collections.Generic;
using static OS.Model.Constants;
using static OS.Model.ProcessModel.CodeSegment;

namespace OS.Model
{
    /// <summary>
    /// data structure of job control block
    /// job is determined as the predecessor of process, which has not been in scheduling
    /// </summary>
    internal class JCB
    {
        #region Var

        private int _jobId;
        private int _priority;
        private int _insNum;
        private List<Instruction> _instructions = new List<Instruction>();

        /// <summary>
        /// basic address for the program to read or write memory
        /// designed to simulate the locality of reference
        /// </summary>
        private Address _basicAddr;
        private static int _idCounter = 0;
        private static Random _ran = new Random();

        #endregion Var

        #region Property

        public int JobId
        {
            get => _jobId;
            set => _jobId = value;
        }

        public int Priority
        {
            get => _priority;
            set => _priority = value;
        }

        public int InsNum
        {
            get => _insNum;
            set => _insNum = value;
        }

        public List<Instruction> Instructions
        {
            get => _instructions;
            set => _instructions = value;
        }

        #endregion Property

        #region Constructor

        /// <summary>
        /// default constructor
        /// create random job
        /// </summary>
        public JCB()
        {
            _jobId = _idCounter++;
            _priority = _ran.Next(1, 6);
            _basicAddr = new Address((ushort)_ran.Next(_insNum * LengthOfIns / Constants.Byte + 1, 0x7f00));
            _insNum = _ran.Next(MinNum, MaxNum);
            for (int i = 0; i < _insNum; i++)
            {
                Instruction ins = new Instruction
                {
                    InsId = i,
                    InsType = i == _insNum - 1 ? InstructionTypes.Return : (InstructionTypes)_ran.Next(0, 4)
                };
                if (ins.InsType == InstructionTypes.ReadMemory || ins.InsType == InstructionTypes.WriteMemory)
                {
                    ins.Addr = new Address((ushort)(_basicAddr.WholeAddress + _ran.Next(0, 0xff)));
                }
                _instructions.Add(ins);
            }
        }

        /// <summary>
        /// constructor which takes params from outer files
        /// </summary>
        /// <param name="priority"></param>
        /// <param name="insNum"></param>
        /// <param name="instructions"></param>
        public JCB(int priority, int insNum, List<Instruction> instructions)
        {
            _jobId = _idCounter++;
            _priority = priority;
            _basicAddr = new Address((ushort)_ran.Next(_insNum * LengthOfIns / Constants.Byte + 1, 0x7f00));
            _insNum = insNum;
            _instructions = instructions;
        }
        #endregion Constructor
    }
}