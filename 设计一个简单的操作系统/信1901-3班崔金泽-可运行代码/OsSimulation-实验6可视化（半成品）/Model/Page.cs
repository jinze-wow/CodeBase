using Prism.Mvvm;
using static OS.Model.Constants;

namespace OS.Model
{
    /// <summary>
    /// simulation of page in memory
    /// </summary>
    internal class Page : BindableBase
    {
        #region Var

        private byte[] _data = new byte[BlockSize];
        //private bool _isDirty;

        #endregion Var

        #region Property

        public byte[] Data
        {
            get => _data;
            set
            {
                SetProperty(ref _data, value);
            }
        }

        #endregion Property
    }
}