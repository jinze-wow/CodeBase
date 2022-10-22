using Prism.Mvvm;
using System.Collections.ObjectModel;
using static OS.Model.ProcessModel;

namespace OS.ViewModel
{
    internal class ListViewModel : BindableBase
    {
        public string ListName { get; set; }
        public ObservableCollection<PCB> ProcessItems { get; set; }

        public ListViewModel()
        {
        }

        public ListViewModel(string name)
        {
            ProcessItems = new ObservableCollection<PCB>();
            ListName = name;
        }

        public ListViewModel(string name, ObservableCollection<PCB> list)
        {
            ListName = name;
            ProcessItems = list;
        }
    }
}