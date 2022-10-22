using Prism.Mvvm;
using System.Collections.Generic;
using static OS.Model.ProcessModel;

namespace OS.Model
{
    /// <summary>
    /// model for list in kernel
    /// </summary>
    internal class ListModel : BindableBase
    {
        private string _listName;
        private List<PCB> _pcbList = new List<PCB>();

        public string ListName
        {
            get => _listName;
            set => SetProperty(ref _listName, value);
        }

        private List<PCB> PcbList
        {
            get => _pcbList;
            set => SetProperty(ref _pcbList, value);
        }

        public ListModel()
        {
        }

        public ListModel(string str)
        {
            _listName = str;
        }
    }
}