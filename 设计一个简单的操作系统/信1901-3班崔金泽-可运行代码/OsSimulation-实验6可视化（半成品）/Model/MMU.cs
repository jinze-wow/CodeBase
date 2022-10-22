using static OS.Model.Constants;

namespace OS.Model
{
    /// <summary>
    /// mmu in cpu
    /// used for convertion between logical and physical address
    /// </summary>
    internal class MMU
    {
        #region inner class

        private class TLB
        {
            private class TlbEntry
            {
                public ushort? PageIndex { get; set; }
                public ushort? FrameIndex { get; set; }
                public int Counter { get; set; }

                public TlbEntry()
                {
                }

                public TlbEntry(ushort pageIndex, ushort frameIndex)
                {
                    this.PageIndex = pageIndex;
                    this.FrameIndex = frameIndex;
                }
            }

            private TlbEntry[] _entries = new TlbEntry[EntriesPerTLB];

            public ushort? GetFrameIndex(ushort pageIndex)
            {
                foreach (TlbEntry entry in _entries)
                {
                    if (pageIndex == entry.PageIndex)
                    {
                        //LRU algorithm
                        entry.Counter = 0;
                        foreach (TlbEntry e in _entries)
                        {
                            if (e != entry)
                            {
                                e.Counter++;
                            }
                        }

                        return entry.FrameIndex;
                    }
                }
                return null;
            }

            public void WriteBack(ushort pageIndex, ushort frameIndex)
            {
                TlbEntry newEntry = new TlbEntry(pageIndex, frameIndex);

                //look for an empty entry
                for (int i = 0; i < EntriesPerTLB; i++)
                {
                    if (_entries[i].PageIndex == null)
                    {
                        _entries[i] = newEntry;
                        return;
                    }
                }

                //swap a resident entry with a biggest counter
                int maxValue = 0, maxIndex = 0;
                for (int i = 0; i < EntriesPerTLB; i++)
                {
                    if (_entries[i].Counter > maxValue)
                    {
                        maxValue = _entries[i].Counter;
                        maxIndex = i;
                    }
                }
                _entries[maxIndex] = newEntry;
            }

            public TLB()
            {
                for (int i = 0; i < 16; i++)
                {
                    _entries[i] = new TlbEntry();
                }
            }
        }

        #endregion inner class

        #region Var

        private TLB _tlb = new TLB();

        #endregion Var

        #region Property

        public PageTable PageTable { get; set; }

        #endregion Property

        #region Methods

        public Address Logical2Physical(Address logicAddr)
        {
            //search TLB
            var frameIndex = _tlb.GetFrameIndex(logicAddr.PageIndex);

            //if found
            if (frameIndex != null)
            {
                return new Address((ushort)frameIndex, logicAddr.Offset);
            }
            //if not found search page table
            else
            {
                frameIndex = PageTable.GetFrameIndex(logicAddr.PageIndex);
                //if found in page table
                if (frameIndex != null)
                {
                    //record it to TLB and return
                    _tlb.WriteBack(logicAddr.PageIndex, (ushort)frameIndex);
                    return new Address((ushort)frameIndex, logicAddr.Offset);
                }
                //not found, return null to imply it
                else
                {
                    return null;
                }
            }
        }

        #endregion Methods
    }
}