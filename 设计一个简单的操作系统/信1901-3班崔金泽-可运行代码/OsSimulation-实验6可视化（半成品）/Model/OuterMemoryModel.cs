using Prism.Mvvm;
using System.Collections.ObjectModel;
using static OS.Model.Constants;

namespace OS.Model
{
    /// <summary>
    /// hard-disk simulation
    /// </summary>
    public class OuterMemoryModel : BindableBase
    {
        #region Inner Class

        public enum SectorType { boot, super, inode, swap, file }

        /// <summary>
        /// data structure of sector
        /// </summary>
        public class Sector
        {
            public byte[] Data { get; set; }
            public int Index { get; set; }
            public bool Occupied { get; set; }
            public SectorType Type { get; set; }

            public Sector()
            {
                Data = new byte[SectorSize];
                Occupied = false;
            }
        }

        /// <summary>
        /// data structure of track
        /// </summary>
        public class Track
        {
            public Sector[] Sectors { get; set; }

            public Track()
            {
                Sectors = new Sector[SectorsPerTrack];
                for (int i = 0; i < SectorsPerTrack; i++)
                {
                    Sectors[i] = new Sector();
                }
            }
        }

        /// <summary>
        /// data structor of cylinder
        /// </summary>
        public class Cylinder
        {
            public Track[] Tracks { get; set; }
            public const int TotalSectors = TracksPerCylinder * SectorsPerTrack;

            public Cylinder()
            {
                Tracks = new Track[TracksPerCylinder];
                for (int i = 0; i < TracksPerCylinder; i++)
                {
                    Tracks[i] = new Track();
                }
            }

            public Sector GetSector(int index)
            {
                int sector = index % SectorsPerTrack;
                int track = index / SectorsPerTrack;
                return Tracks[track].Sectors[sector];
            }
        }

        private class DiskArea
        {
            public string Name { get; set; }
            public int StartSector { get; set; }
            public int EndSector { get; set; }

            public int Length
            {
                get => EndSector - StartSector + 1;
            }
        }

        #endregion Inner Class

        #region var

        private Cylinder _data;

        #endregion var

        #region DiskArea Definitions

        private readonly DiskArea _boot = new DiskArea()
        {
            Name = "boot",
            StartSector = 0,
            EndSector = 0
        };

        private readonly DiskArea _super = new DiskArea()
        {
            Name = "super",
            StartSector = 1,
            EndSector = 1
        };

        private readonly DiskArea _inode = new DiskArea()
        {
            Name = "inode",
            StartSector = 2,
            EndSector = 63
        };

        private DiskArea _swap = new DiskArea()
        {
            Name = "swap",
            StartSector = 64,
            EndSector = 192
        };

        private readonly DiskArea _file = new DiskArea()
        {
            Name = "file",
            StartSector = 193,
            EndSector = Cylinder.TotalSectors - 1
        };

        #endregion DiskArea Definitions

        #region Property

        /// <summary>
        /// return first empty block in swap area
        /// </summary>
        public int EmptySwapBlock
        {
            get
            {
                int blockCount = 0;
                for (int i = _swap.StartSector; i <= _swap.EndSector; i++)
                {
                    if (!GetSector(i).Occupied)
                    {
                        blockCount++;
                    }
                }
                return blockCount;
            }
        }

        #endregion Property

        #region Methods

        public Sector GetSector(int index)
        {
            return _data.GetSector(index);
        }

        /// <summary>
        /// write a sector in swap area
        /// </summary>
        /// <returns></returns>
        public int WriteInSwapSector()
        {
            for (int i = _swap.StartSector; i <= _swap.EndSector; i++)
            {
                if (!_data.GetSector(i).Occupied)
                {
                    _data.GetSector(i).Occupied = true;
                    return i;
                }
            }
            return 0;
        }

        public ObservableCollection<Sector> Collection
        {
            get
            {
                var collection = new ObservableCollection<Sector>();
                for (int i = 0; i < SectorsPerTrack * TracksPerCylinder; i++)
                {
                    collection.Add(GetSector(i));
                }
                return collection;
            }
        }

        #endregion Methods

        #region Constructor

        public OuterMemoryModel()
        {
            _data = new Cylinder();
            for (int i = 0; i < SectorsPerTrack * TracksPerCylinder; i++)
            {
                var sector = GetSector(i);
                sector.Index = i;
                if (i == 0)
                {
                    sector.Type = SectorType.boot;
                    sector.Occupied = true;
                }
                else if (i == 1)
                {
                    sector.Type = SectorType.super;
                    sector.Occupied = true;
                }
                else if (i < 64)
                    sector.Type = SectorType.inode;
                else if (i < 192)
                    sector.Type = SectorType.swap;
                else
                    sector.Type = SectorType.file;
            }
        }

        #endregion Constructor
    }
}