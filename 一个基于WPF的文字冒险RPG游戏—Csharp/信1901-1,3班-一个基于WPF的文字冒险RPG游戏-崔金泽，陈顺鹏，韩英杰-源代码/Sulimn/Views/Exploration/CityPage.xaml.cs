using Extensions;
using Sulimn.Classes;
using Sulimn.Views.BankPages;
using Sulimn.Views.Characters;
using Sulimn.Views.Options;
using Sulimn.Views.Shopping;
using System.Windows;

namespace Sulimn.Views.Exploration
{
    /// <summary>Interaction logic for CityPage.xaml</summary>
    public partial class CityPage
    {
        /// <summary>Is a newly created <see cref="Hero"/> logging in for the first time?</summary>
        internal bool NewHero { get; set; }

        #region Button-Click Methods

        private void BtnBank_Click(object sender, RoutedEventArgs e)
        {
            BankPage bankPage = new BankPage();
            bankPage.LoadBank();
            GameState.Navigate(bankPage);
        }

        private void BtnChapel_Click(object sender, RoutedEventArgs e)
        {
            if (
            decimal.Divide(GameState.CurrentHero.Statistics.CurrentHealth,
            GameState.CurrentHero.Statistics.MaximumHealth) <= 0.25M)
            {
                Functions.AddTextToTextBox(TxtCity, "你进入一个当地的小教堂，走近祭坛。一位牧师走近你。\n" +
                "\"让我来治愈你的伤口。你看起来像是经历了一场艰苦的战斗。\"\n" +
                "牧师给了你一瓶药水，可以治愈你的生命!n" +
                "你感谢牧师，回到街上去。");
                GameState.CurrentHero.Statistics.CurrentHealth = GameState.CurrentHero.Statistics.MaximumHealth;

                GameState.SaveHero(GameState.CurrentHero);
            }
            else
            {
                Functions.AddTextToTextBox(TxtCity, "你走进一个当地的小教堂。一位牧师走近你。\n" +
                "\"我看你很健康如果你需要治愈，请随时来找我。\"\n\n" +
                "你感谢牧师，回到街上去。");
            }
        }

        private void BtnCharacter_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new CharacterPage());

        private void BtnExit_Click(object sender, RoutedEventArgs e)
        {
            if (GameState.YesNoNotification("你确定要退出吗?", "苏立明"))
            {
                GameState.GoBack();
                GameState.MainWindow.StatsFrame.Visibility = Visibility.Collapsed;
                GameState.MainWindow.StatsFrame.Content = null;
                while (GameState.MainWindow.StatsFrame.NavigationService.RemoveBackEntry() != null) ;
            }
        }

        private void BtnExplore_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new ExplorePage());

        private void BtnMarket_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new MarketPage());

        private void BtnOptions_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new HeroChangePasswordPage());

        private void BtnTavern_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new TavernPage());

        #endregion Button-Click Methods

        #region Page-Generated Methods

        /// <summary>Closes the Page.</summary>

        public CityPage()
        {
            InitializeComponent();
            TxtCity.Text =
            "你现在是在苏利明城。市中心有一个熙熙攘攘的市场，北端一座破败的大教堂在城市景观中蔓延开来，南侧是一个废弃的矿业综合体，东边是农田，西边是森林。";
        }

        private void CityPage_OnLoaded(object sender, RoutedEventArgs e)
        {
            if (NewHero)
            {
                GameState.MainWindow.MainFrame.RemoveBackEntry();
                NewHero = false;
            }
            GameState.MainWindow.StatsFrame.Navigate(new StatsPage());
            GameState.MainWindow.StatsFrame.Visibility = Visibility.Visible;
        }

        #endregion Page-Generated Methods
    }
}