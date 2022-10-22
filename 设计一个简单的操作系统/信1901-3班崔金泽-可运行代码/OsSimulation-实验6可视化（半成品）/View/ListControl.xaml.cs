using OS.ViewModel;
using System.Windows;
using System.Windows.Controls;

namespace OS.View
{
    /// <summary>
    /// ListControl.xaml 的交互逻辑
    /// </summary>
    public partial class ListControl : UserControl
    {
        public ListControl()
        {
            InitializeComponent();
            this.DataContext = new ListViewModel();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
        }
    }
}