using OS.Model;
using Prism.Mvvm;
using static OS.Model.Constants;

namespace OS
{
    /// <summary>
    /// simulation of cpu
    /// a cpu consists of mmu and clock
    /// </summary>
    internal class CpuModel : BindableBase
    {
        #region static

        public MMU mmu;
        private ClockModel clock;
        //public int IR;

        #endregion static

        #region var

        private CpuModes _cpuMode;

        #endregion var

        #region proprety

        public CpuModes CpuMode
        {
            get => _cpuMode;
            set
            {
                SetProperty(ref _cpuMode, value);
            }
        }

        public ClockModel Clock
        {
            get => clock;
            set => SetProperty(ref clock, value);
        }

        #endregion proprety

        #region constructor

        public CpuModel()
        {
            clock = new ClockModel();
            mmu = new MMU();
        }

        #endregion constructor
    }
}