using Prism.Mvvm;
using static OS.Model.ProcessModel;

namespace OS.ViewModel
{
    internal class PcbViewModel : BindableBase
    {
        private PCB _pcb;

        public PCB Pcb
        {
            get => _pcb;
            set => SetProperty(ref _pcb, value);
        }

        public PcbViewModel(PCB pcb)
        {
            _pcb = pcb;
        }
    }
}