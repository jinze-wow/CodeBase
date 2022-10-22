using Extensions;
using Sulimn.Classes;
using Sulimn.Classes.Enums;
using System.ComponentModel;
using System.Windows;

namespace Sulimn.Views.BankPages
{
    /// <summary>Interaction logic for BankPage.xaml</summary>
    public partial class BankPage : INotifyPropertyChanged
    {
        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>Binds text to the labels.</summary>
        private void BindLabels()
        {
            DataContext = GameState.CurrentHero.Bank;
            LblGoldOnHand.DataContext = GameState.CurrentHero;
        }

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Display Manipulation

        /// <summary>Adds text to the TxtBank Textbox.</summary>
        /// <param name="newText">Text to be added</param>
        internal void AddTextToTextBox(string newText) => Functions.AddTextToTextBox(TxtBank, newText);

        /// <summary>Checks what buttons should be enabled.</summary>
        internal void CheckButtons()
        {
            BtnDeposit.IsEnabled = GameState.CurrentHero.Gold > 0;
            BtnWithdraw.IsEnabled = GameState.CurrentHero.Bank.GoldInBank > 0;
            BtnTakeLoan.IsEnabled = GameState.CurrentHero.Bank.LoanAvailable > 0;
            BtnRepayLoan.IsEnabled = GameState.CurrentHero.Bank.LoanTaken > 0;
        }

        /// <summary>Displays the Bank Dialog Page.</summary>
        /// <param name="maximum">Maximum amount of Gold permitted</param>
        /// <param name="type">Type of Page information to be displayed</param>
        private void DisplayBankDialog(int maximum, BankAction type)
        {
            BankDialogPage bankDialogPage = new BankDialogPage();
            bankDialogPage.LoadPage(maximum, type);
            bankDialogPage.RefToBankPage = this;
            GameState.Navigate(bankDialogPage);
        }

        /// <summary>Loads the initial Bank state and Hero's Bank information..</summary>
        internal void LoadBank()
        {
            TxtBank.Text =
            "你进入银行。出纳员向你招手，你走近他。你告诉他你的名字，他就翻了几份文件。他找到一个，把它拉了出来。\n\n" +
            $"你拥有 {GameState.CurrentHero.Bank.GoldInBankToString} 黄金可供提取。你还有一个开放的信用额度 { GameState.CurrentHero.Bank.LoanAvailableToString} 金.";
            BindLabels();
            CheckButtons();
        }

        #endregion Display Manipulation

        #region Button-Click Methods

        private void BtnBack_Click(object sender, RoutedEventArgs e) => ClosePage();

        private void BtnDeposit_Click(object sender, RoutedEventArgs e) => DisplayBankDialog(GameState.CurrentHero.Gold, BankAction.Deposit);

        private void BtnRepayLoan_Click(object sender, RoutedEventArgs e) => DisplayBankDialog(GameState.CurrentHero.Bank.LoanTaken, BankAction.Repay);

        private void BtnTakeLoan_Click(object sender, RoutedEventArgs e) => DisplayBankDialog(GameState.CurrentHero.Bank.LoanAvailable, BankAction.Borrow);

        private void BtnWithdraw_Click(object sender, RoutedEventArgs e) => DisplayBankDialog(GameState.CurrentHero.Bank.GoldInBank, BankAction.Withdrawal);

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            GameState.SaveHero(GameState.CurrentHero);
            GameState.GoBack();
        }

        public BankPage() => InitializeComponent();

        #endregion Page-Manipulation Methods
    }
}