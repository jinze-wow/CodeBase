using Extensions;
using Sulimn.Classes;
using System.Windows;
using System.Windows.Controls;

namespace Sulimn.Views.Exploration
{
    /// <summary>Interaction logic for ExplorePage.xaml</summary>
    public partial class ExplorePage
    {
        #region Button Manipulation

        /// <summary>Checks the player's level to determine which buttons to allow to be enabled.</summary>
        private void CheckButtons()
        {
            BtnBack.IsEnabled = true;
            BtnFields.IsEnabled = true;
            BtnForest.IsEnabled = GameState.CurrentHero.Level >= 5 && GameState.CurrentHero.Progression.Fields;
            BtnCathedral.IsEnabled = GameState.CurrentHero.Level >= 10 && GameState.CurrentHero.Progression.Forest;
            BtnMines.IsEnabled = GameState.CurrentHero.Level >= 15 && GameState.CurrentHero.Progression.Cathedral;
            BtnCatacombs.IsEnabled = GameState.CurrentHero.Level >= 20 && GameState.CurrentHero.Progression.Mines;
            BtnCastle.IsEnabled = GameState.CurrentHero.Level >= 25 && GameState.CurrentHero.Progression.Catacombs;
        }

        /// <summary>Does the Hero have more than zero health?</summary>
        /// <returns>Whether the Hero has more than zero health</returns>
        private bool Healthy()
        {
            if (GameState.CurrentHero.Statistics.CurrentHealth > 0) return true;
            Functions.AddTextToTextBox(TxtExplore, "You need to heal before you can explore.");
            return false;
        }

        private void Navigate(Page page)
        {
            if (Healthy())
                GameState.Navigate(page);
        }

        #endregion Button Manipulation

        #region Button-Click Methods

        private void BtnBack_Click(object sender, RoutedEventArgs e) => GameState.GoBack();

        private void BtnCatacombs_Click(object sender, RoutedEventArgs e) => Navigate(new CatacombsPage());

        private void BtnCastle_Click(object sender, RoutedEventArgs e)
        {//Navigate(new CastlePage());
        }

        private void BtnCathedral_Click(object sender, RoutedEventArgs e) => Navigate(new CathedralPage());

        private void BtnFields_Click(object sender, RoutedEventArgs e) => Navigate(new FieldsPage());

        private void BtnForest_Click(object sender, RoutedEventArgs e) => Navigate(new ForestPage());

        private void BtnMines_Click(object sender, RoutedEventArgs e) => Navigate(new MinesPage());

        #endregion Button-Click Methods

        #region Page-Generated Methods

        public ExplorePage()
        {
            InitializeComponent();
            TxtExplore.Text =
            "在东部有一些看起来很安全的农场和农田，许多冒险家都曾去那里证明自己的价值。\n\n" +
            "西边有一片黑暗的森林，似乎已经吞噬了不少冒险家。\n\n" +
            "在城市的北端有一座破败的大教堂，在它的阴影下向每个人传播着恐惧和绝望。\n\n" +
            "在城市的南侧有一个废弃的矿区，看起来已经很多年没有人进出了。\n\n" +
            "你也听说过城市下面有地下墓穴的故事。在你探索了更多关于苏利曼的地方之后，入口就会出现。";
        }

        private void ExplorePage_OnLoaded(object sender, RoutedEventArgs e) => CheckButtons();

        #endregion Page-Generated Methods
    }
}