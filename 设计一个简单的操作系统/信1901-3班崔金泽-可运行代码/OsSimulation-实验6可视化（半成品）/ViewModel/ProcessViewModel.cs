using OS.Model;
using Prism.Mvvm;
using static OS.Model.ProcessModel;

namespace OS.ViewModel
{
    internal class ProcessViewModel : BindableBase
    {
        private ProcessModel processModel;

        public ProcessViewModel()
        {
            processModel = new ProcessModel();
        }

        public ProcessViewModel(ProcessModel processModel)
        {
            this.ProcessModel = processModel;
        }

        public ProcessViewModel(PCB pcb)
        {
            this.ProcessModel = pcb.ProcessRef;
        }

        public ProcessModel ProcessModel
        {
            get => processModel;
            set
            {
                SetProperty(ref processModel, value);
            }
        }
    }
}