using Prism.Mvvm;
using System.Windows.Threading;

namespace OS.Model
{
    /// <summary>
    /// simulation of clock in cpu
    /// </summary>
    internal class ClockModel : BindableBase
    {
        #region var
        /// <summary>
        /// recording seconds passed
        /// </summary>
        private long _counter;

        /// <summary>
        /// the interval of the clock (ms)
        /// </summary>
        private int _timeSpan;

        private DispatcherTimer _timer;

        #endregion var

        #region property

        public long Counter
        {
            get => _counter;
            set
            {
                SetProperty(ref _counter, value);
            }
        }

        public int TimeSpan
        {
            get => _timeSpan;
            set => _timeSpan = value;
        }

        public DispatcherTimer Timer
        {
            get => _timer;
            set
            {
                SetProperty(ref _timer, value);
            }
        }

        #endregion property

        #region Constructor

        public ClockModel(int timeSpan = 1000)
        {
            Counter = 0;
            TimeSpan = timeSpan;
            Timer = new DispatcherTimer
            {
                Interval = System.TimeSpan.FromMilliseconds(TimeSpan)
            };
        }

        #endregion Constructor

        #region Methods

        public void Start()
        {
            Timer.Start();
        }

        public void Pause()
        {
            Timer.Stop();
        }

        public void Restart()
        {
            Timer.Stop();
            Counter = 0;
            Timer.Start();
        }

        #endregion Methods
    }
}