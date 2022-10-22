namespace OS.Model
{
    /// <summary>
    /// 16-bit address
    /// divided into two parts: 7-bit PageIndex and 9-bit Offset
    /// </summary>
    internal class Address
    {
        #region property

        public ushort PageIndex { get; set; }

        public ushort Offset { get; set; }

        public ushort WholeAddress
        {
            get => (ushort)(PageIndex << 9 + Offset);
            set
            {
                ushort mask = 0b111111111;
                Offset = (ushort)(value & mask);
                PageIndex = (ushort)(value >> 9);
            }
        }

        #endregion property

        #region constructor

        public Address()
        {
        }

        public Address(ushort pageIndex, ushort offset)
        {
            PageIndex = pageIndex;
            Offset = offset;
        }

        public Address(ushort wholeAddress) => WholeAddress = wholeAddress;

        #endregion constructor
    }
}