using Prism.Mvvm;
using static OS.Model.Constants;

namespace OS.Model
{
    /// <summary>
    /// data structure of physical memory(real ram)
    /// </summary>
    internal class PhysicalMemoryModel : BindableBase
    {
        #region Var

        private Condition[] _alloMap = new Condition[PhysicalFrameNum];
        private Page[] _pages = new Page[PhysicalFrameNum];

        #endregion Var

        #region Inner Class

        public class Condition : BindableBase
        {
            private int _index;
            private bool _occupied;
            private bool _isKernel;

            public int Index { get => _index; set => SetProperty(ref _index, value); }
            public bool Occupied { get => _occupied; set => SetProperty(ref _occupied, value); }
            public bool IsKernel { get => _isKernel; set => SetProperty(ref _isKernel, value); }
        }

        #endregion Inner Class

        #region Property

        public Condition[] AlloMap
        {
            get => _alloMap;
            set
            {
                SetProperty(ref _alloMap, value);
            }
        }

        public Page[] Pages
        {
            get => _pages;
            set
            {
                SetProperty(ref _pages, value);
            }
        }

        public int? FreePageTable
        {
            get
            {
                for (int i = KernelSplit; i < PageTableSplit; i++)
                {
                    if (!AlloMap[i].Occupied)
                    {
                        return i;
                    }
                }
                return null;
            }
        }

        #endregion Property

        #region Constructor

        public PhysicalMemoryModel()
        {
            for (int i = 0; i < PhysicalFrameNum; i++)
            {
                _pages[i] = new Page();
                _alloMap[i] = new Condition
                {
                    Index = i,
                    Occupied = false,
                    IsKernel = i < PageTableSplit ? true : false
                };
            }
        }

        #endregion Constructor

        #region Methods

        /// <summary>
        /// find one free frame
        /// if found, return frame index
        /// if not, return null
        /// </summary>
        /// <returns></returns>
        public ushort? FindOneFreeFrame()
        {
            for (int i = PageTableSplit; i < PhysicalFrameNum; i++)
            {
                if (AlloMap[i].Occupied == false)
                {
                    return (ushort)i;
                }
            }
            return null;
        }

        #endregion Methods
    }
}