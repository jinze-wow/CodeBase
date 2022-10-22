using Prism.Mvvm;
using System;
using System.Windows.Threading;
using static OS.Model.Constants;

namespace OS.Model
{
    /// <summary>
    /// data structure of page table
    /// </summary>
    internal class PageTable : BindableBase
    {
        //each entry 4B
        //each page table = 4B * 128 = 512B = 1 frame
        public class PageTableEntry
        {
            public ushort FrameNo { get; set; }
            public bool Present { get; set; }
            public bool Referred { get; set; }
            public bool Modified { get; set; }

            //a special register for LRU algorithm
            public byte Register { get; set; }  //only use lower 4 bits
        }

        private PageTableEntry[] _entries = new PageTableEntry[LogicalFrameNum];
        private DispatcherTimer _rightShiftTimer;

        public PageTableEntry[] Entries
        {
            get => _entries;
            set
            {
                SetProperty(ref _entries, value);
            }
        }

        #region Constructor

        public PageTable()
        {
            for (int i = 0; i < _entries.Length; i++)
            {
                _entries[i] = new PageTableEntry();
            }
            _rightShiftTimer = new DispatcherTimer();
            _rightShiftTimer.Tick += _rightShiftTimer_Tick;
            _rightShiftTimer.Interval = TimeSpan.FromSeconds(5);
            _rightShiftTimer.Start();
        }

        #endregion Constructor

        #region Methods

        /// <summary>
        /// right-shift the special register
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void _rightShiftTimer_Tick(object sender, System.EventArgs e)
        {
            foreach (PageTableEntry entry in _entries)
            {
                entry.Register >>= 1;
            }
        }

        public ushort? GetFrameIndex(ushort logicalPage)
        {
            PageTableEntry entry = _entries[logicalPage];
            if (entry.Present)
            {
                return entry.FrameNo;
            }
            else
            {
                return null;
            }
        }

        public void LoadEntry()
        {
        }

        /// <summary>
        /// find an entry least recently used to replace
        /// </summary>
        /// <returns></returns>
        public int Entry2Replace()
        {
            byte minValue = 0b1111;
            int minIndex = 0;
            for (int i = 0; i < _entries.Length; i++)
            {
                if (_entries[i].Register < minValue)
                {
                    minValue = _entries[i].Register;
                    minIndex = i;
                }
            }

            return minIndex;
        }

        #endregion Methods
    }
}