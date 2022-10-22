using OS.Model;
using Prism.Commands;
using Prism.Mvvm;
using System.Collections.ObjectModel;
using System.IO;
using System.Windows;
using static OS.Model.OuterMemoryModel;
using Condition = OS.Model.PhysicalMemoryModel.Condition;

namespace OS.ViewModel
{
    internal class MainWindowViewModel : BindableBase
    {
        private Kernel _kernel;

        public PcbViewModel Running { get; set; }
        public ListViewModel ReadyList { get; set; }
        public ListViewModel BlockList { get; set; }
        public ListViewModel Reserve { get; set; }
        public ObservableCollection<Condition> Memory { get; set; }
        public ObservableCollection<Sector> Disk { get; set; }

        public Kernel Kernel
        {
            get => _kernel;
            set => SetProperty(ref _kernel, value);
        }

        public DelegateCommand OnStart { get; private set; }
        public DelegateCommand OnClose { get; private set; }
        public DelegateCommand OnPause { get; private set; }
        public DelegateCommand OnCreate { get; private set; }

        private static bool PauseOrResume = false;
        private static bool IsStarted = false;

        public MainWindowViewModel()
        {
            Kernel = new Kernel();
            Kernel.InitializeHardwares();
            Kernel.LoadInKernel();
            Kernel.InitializeLists();

            Running = new PcbViewModel(Kernel.Running);
            ReadyList = new ListViewModel("Ready", Kernel.ReadyList);
            BlockList = new ListViewModel("Block", Kernel.BlockList);
            Reserve = new ListViewModel("Reserve", Kernel.ReserveQueue);

            Memory = Kernel.Memory;
            Disk = Kernel.Disk;

            OnStart = new DelegateCommand(() =>
            {
                IsStarted = true;
                OnStart.RaiseCanExecuteChanged();
                OnPause.RaiseCanExecuteChanged();
                OnCreate.RaiseCanExecuteChanged();
                Kernel.InitializeThreads();
            }, () => !IsStarted);

            OnPause = new DelegateCommand(() =>
            {
                if (PauseOrResume == false)
                {
                    Kernel.PauseThreads();
                    PauseOrResume = true;
                }
                else
                {
                    Kernel.ResumeThreads();
                    PauseOrResume = false;
                }
            }, () => IsStarted);

            OnCreate = new DelegateCommand(() => Kernel.CreateJob(), () => IsStarted);

            OnClose = new DelegateCommand(() =>
            {
                using (StreamWriter sw = new StreamWriter("log.txt"))
                {
                    sw.Write(Kernel.Log);
                }
                Application.Current.Shutdown();
            }
            );
        }
    }
}