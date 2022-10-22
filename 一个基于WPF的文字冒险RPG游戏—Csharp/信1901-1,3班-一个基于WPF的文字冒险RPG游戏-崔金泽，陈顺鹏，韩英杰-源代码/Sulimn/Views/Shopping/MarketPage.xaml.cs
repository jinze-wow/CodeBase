using Sulimn.Classes;
using System.Windows;

namespace Sulimn.Views.Shopping
{
    /// <summary>Interaction logic for MarketPage.xaml</summary>
    public partial class MarketPage
    {
        #region Button-Click Methods

        private void BtnWeaponShop_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new WeaponsRUsPage());

        private void BtnArmorShop_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new TheArmouryPage());

        private void BtnGeneralStore_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new TheGeneralStorePage());

        private void BtnMagicShop_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new MagickShoppePage());

        private void BtnSilverEmpire_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new SilverEmpirePage());

        private void BtnSmithy_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new TheSmithyPage());

        private void BtnBack_Click(object sender, RoutedEventArgs e) => GameState.GoBack();

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>

        public MarketPage()
        {
            InitializeComponent();
            TxtMarket.Text = "你进入一个熙熙攘攘的市场。这里有许多商店，最有趣的是:\n\n" +
            "武器反斗城-一家武器商店。\n\n" +
            "军械库-一家军械库。\n\n" +
            "杂货店-供应一般商品如药水的商店。\n\n" +
            "老魔法商店-卖魔法咒语和装备的商店。\n\n" +
            "银制帝国-卖最好的珠宝的铁匠。";
        }

        #endregion Page-Manipulation Methods
    }
}