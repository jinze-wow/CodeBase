﻿using Extensions;
using Sulimn.Classes;
using Sulimn.Classes.Items;
using Sulimn.Views.Characters;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace Sulimn.Views.Shopping
{
    /// <summary>Interaction logic for WeaponsRUsPage.xaml</summary>
    public partial class WeaponsRUsPage : INotifyPropertyChanged
    {
        private List<Item> _purchaseWeapon = new List<Item>();
        private Item _selectedWeaponPurchase = new Item();
        private Item _selectedWeaponSell = new Item();
        private List<Item> _sellWeapon = new List<Item>();

        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        private void BindWeaponPurchase(bool reload = true)
        {
            if (reload)
            {
                _purchaseWeapon.Clear();
                _purchaseWeapon.AddRange(GameState.GetItemsOfType(ItemType.MeleeWeapon).Where(weapon => weapon.IsSold));
                _purchaseWeapon.AddRange(GameState.GetItemsOfType(ItemType.RangedWeapon).Where(weapon => weapon.IsSold));
                _purchaseWeapon = _purchaseWeapon.OrderBy(weapon => weapon.Value).ToList();
                LstWeaponPurchase.ItemsSource = _purchaseWeapon;
                LstWeaponPurchase.Items.SortDescriptions.Add(new SortDescription("Value", ListSortDirection.Ascending));
                LstWeaponPurchase.Items.Refresh();
            }
            LblWeaponNamePurchase.DataContext = _selectedWeaponPurchase;
            LblWeaponDamagePurchase.DataContext = _selectedWeaponPurchase;
            LblWeaponDescriptionPurchase.DataContext = _selectedWeaponPurchase;
            LblWeaponTypePurchase.DataContext = _selectedWeaponPurchase;
            LblWeaponSellablePurchase.DataContext = _selectedWeaponPurchase;
            LblWeaponValuePurchase.DataContext = _selectedWeaponPurchase;
        }

        private void BindWeaponSell(bool reload = true)
        {
            if (reload)
            {
                _sellWeapon.Clear();
                _sellWeapon.AddRange(GameState.CurrentHero.GetItemsOfType(ItemType.MeleeWeapon));
                _sellWeapon.AddRange(GameState.CurrentHero.GetItemsOfType(ItemType.RangedWeapon));
                _sellWeapon = _sellWeapon.OrderBy(weapon => weapon.Value).ToList();
                LstWeaponSell.ItemsSource = _sellWeapon;
                LstWeaponSell.Items.SortDescriptions.Add(new SortDescription("SellValue", ListSortDirection.Ascending));
                LstWeaponSell.Items.Refresh();
            }
            LblWeaponNameSell.DataContext = _selectedWeaponSell;
            LblWeaponDamageSell.DataContext = _selectedWeaponSell;
            LblWeaponDescriptionSell.DataContext = _selectedWeaponSell;
            LblWeaponTypeSell.DataContext = _selectedWeaponSell;
            LblWeaponSellableSell.DataContext = _selectedWeaponSell;
            LblWeaponValueSell.DataContext = _selectedWeaponSell;
        }

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Load

        /// <summary>Loads all the required data.</summary>
        internal void LoadAll()
        {
            LoadAllPurchase();
            LoadAllSell();

            LblGold.DataContext = GameState.CurrentHero;
        }

        private void LoadAllPurchase() => BindWeaponPurchase();

        private void LoadAllSell() => BindWeaponSell();

        #endregion Load

        #region Transaction Methods

        /// <summary>Purchases selected Item.</summary>
        /// <param name="itmPurchase">Item to be purchased</param>
        /// <returns>Returns text about the purchase</returns>
        private string Purchase(Item itmPurchase)
        {
            GameState.CurrentHero.Gold -= itmPurchase.Value;
            GameState.CurrentHero.AddItem(itmPurchase);
            //TODO Try to remember why I loaded all possible purchases every single time I made a purchase. It doesn't make sense.
            LoadAllPurchase();
            LoadAllSell();
            BtnWeaponPurchase.IsEnabled = _selectedWeaponPurchase.Value > 0 && _selectedWeaponPurchase.Value <= GameState.CurrentHero.Gold;
            return $"You have purchased {itmPurchase.Name} for {itmPurchase.ValueToString} gold.";
        }

        /// <summary>Sells selected Item.</summary>
        /// <param name="itmSell">Item to be sold</param>
        /// <returns>Returns text about the sale</returns>
        private string Sell(Item itmSell)
        {
            GameState.CurrentHero.Gold += itmSell.SellValue;
            GameState.CurrentHero.RemoveItem(itmSell);
            LoadAllSell();
            BtnWeaponPurchase.IsEnabled = _selectedWeaponPurchase.Value > 0 && _selectedWeaponPurchase.Value <= GameState.CurrentHero.Gold;
            return $"You have sold your {itmSell.Name} for {itmSell.SellValueToString} gold.";
        }

        #endregion Transaction Methods

        #region Purchase/Sell Button-Click Methods

        private void BtnWeaponPurchase_Click(object sender, RoutedEventArgs e)
        {
            Functions.AddTextToTextBox(TxtWeaponsRUs, Purchase(_selectedWeaponPurchase));
            LstWeaponPurchase.UnselectAll();
        }

        private void BtnWeaponSell_Click(object sender, RoutedEventArgs e)
        {
            Functions.AddTextToTextBox(TxtWeaponsRUs, Sell(_selectedWeaponSell));
            LstWeaponSell.UnselectAll();
        }

        #endregion Purchase/Sell Button-Click Methods

        #region Purchase/Sell Selection Changed

        private void LstWeaponPurchase_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _selectedWeaponPurchase = LstWeaponPurchase.SelectedIndex >= 0
            ? (Item)LstWeaponPurchase.SelectedValue
            : new Item();

            BtnWeaponPurchase.IsEnabled = _selectedWeaponPurchase.Value > 0 && _selectedWeaponPurchase.Value <= GameState.CurrentHero.Gold;
            BindWeaponPurchase(false);
        }

        private void LstWeaponSell_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _selectedWeaponSell = LstWeaponSell.SelectedIndex >= 0 ? (Item)LstWeaponSell.SelectedValue : new Item();

            BtnWeaponSell.IsEnabled = _selectedWeaponSell.CanSell;
            BindWeaponSell(false);
        }

        #endregion Purchase/Sell Selection Changed

        #region Page Button-Click Methods

        private void BtnCharacter_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new CharacterPage());

        private void BtnBack_Click(object sender, RoutedEventArgs e) => ClosePage();

        #endregion Page Button-Click Methods

        #region Page-Manipulation

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            GameState.SaveHero(GameState.CurrentHero);
            GameState.GoBack();
        }

        public WeaponsRUsPage()
        {
            InitializeComponent();
            TxtWeaponsRUs.Text =
            "你进入了武器反斗城，苏利民市最好的武器厂。你走近店主，他向你展示他的商品";
        }

        private void WeaponsRUsPage_OnLoaded(object sender, RoutedEventArgs e) => LoadAll();

        #endregion Page-Manipulation
    }
}