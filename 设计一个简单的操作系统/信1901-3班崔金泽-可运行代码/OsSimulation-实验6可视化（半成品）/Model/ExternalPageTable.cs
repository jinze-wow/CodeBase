using Prism.Mvvm;
using System.Collections.Generic;

namespace OS.Model
{
    /// <summary>
    /// data structure of a external page table
    /// used in data exchange between swap area and RAM
    /// </summary>
    internal class ExternalPageTable : BindableBase
    {
        /// <summary>
        /// data structure of external page entry
        /// consists of two parts : page index(in RAM) and block number(in hard-disk)
        /// </summary>
        public class ExternalPageEntry
        {
            public ushort PageIndex { get; set; }
            public ushort BlockNumber { get; set; }

            public ExternalPageEntry()
            {
            }

            public ExternalPageEntry(ushort pageIndex, ushort blockNum)
            {
                PageIndex = pageIndex;
                BlockNumber = blockNum;
            }
        }

        private List<ExternalPageEntry> _pageEntries = new List<ExternalPageEntry>();

        public List<ExternalPageEntry> PageEntries
        {
            get => _pageEntries;
            set
            {
                SetProperty(ref _pageEntries, value);
            }
        }

        #region Methods

        /// <summary>
        /// find a block in hard-disk with the address in RAM
        /// if found return block num
        /// if not return null
        /// </summary>
        /// <param name="addr"></param>
        /// <returns></returns>
        public ushort? GetBlockNum(Address addr)
        {
            foreach (ExternalPageEntry entry in _pageEntries)
            {
                if (entry.PageIndex == addr.PageIndex)
                {
                    return entry.BlockNumber;
                }
            }
            return null;
        }

        /// <summary>
        /// find a block in hard-disk with the page index in RAM
        /// if found return block num
        /// if not return null
        /// </summary>
        /// <param name="pageIndex"></param>
        /// <returns></returns>
        public ushort? GetBlockNum(ushort pageIndex)
        {
            foreach (ExternalPageEntry entry in _pageEntries)
            {
                if (entry.PageIndex == pageIndex)
                {
                    return entry.BlockNumber;
                }
            }
            return null;
        }

        #endregion Methods
    }
}