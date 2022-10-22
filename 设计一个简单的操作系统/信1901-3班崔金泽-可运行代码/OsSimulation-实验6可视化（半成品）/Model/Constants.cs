namespace OS.Model
{
    /// <summary>
    /// a static class storing constants
    /// </summary>
    internal static class Constants
    {
        #region Storage

        public const int Memory = 32 * 1024;
        public const int BlockSize = 512;
        public const int PhysicalFrameNum = Memory / BlockSize;
        public const int LogicalFrameNum = 128;
        public const int AddressLength = 16;
        public const int SectorSize = 512;
        public const int SectorsPerTrack = 64;
        public const int TracksPerCylinder = 32;

        #region RAM split

        public const int KernelSplit = 4;
        public const int PageTableSplit = 32;
        public const int UserSplit = PhysicalFrameNum;

        #endregion RAM split

        #endregion Storage

        #region Address

        public const int PhysicalNo = 6;
        public const int LogicalNo = 7;
        public const int Offset = 9;

        #endregion Address

        #region Process

        #region Schedule

        public const int TimeSlice = 4;
        public const int CreateJobMin = 3;
        public const int CreateJobMax = 10;
        public const int BlockTimeMax = 5;
        public const int BlockTimeMin = 2;

        #endregion Schedule

        #region Instructions

        public const int Byte = 8;
        public const int LengthOfIns = 32;
        public const int MinNum = 5;
        public const int MaxNum = 20;

        #endregion Instructions

        #endregion Process

        #region Entries

        public const int EntriesPerTLB = 16;

        #endregion Entries

        #region Enum

        public enum CpuModes { system, user };

        public enum InstructionTypes { Calculate, ReadMemory, WriteMemory, SystemCall, Return }

        #endregion Enum
    }
}