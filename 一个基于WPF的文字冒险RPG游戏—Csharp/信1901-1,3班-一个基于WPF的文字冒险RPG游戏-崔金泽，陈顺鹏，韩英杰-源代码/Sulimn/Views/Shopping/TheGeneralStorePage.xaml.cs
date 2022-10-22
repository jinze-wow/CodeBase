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
    /// <summary>Interaction logic for TheGeneralStorePage.xaml</summary>
    public partial class TheGeneralStorePage : INotifyPropertyChanged
    {
        private List<Item> _purchasePotion = new List<Item>();
        private Item _selectedPotionPurchase = new Item();
        private Item _selectedPotionSell = new Item();
        private List<Item> _sellPotion = new List<Item>();

        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        private void BindPotionPurchase(bool reload = true)
        {
            if (reload)
            {
                _purchasePotion.Clear();
                _purchasePotion.AddRange(GameState.GetItemsOfType(ItemType.Potion).Where(potion => potion.IsSold));
                _purchasePotion = _purchasePotion.OrderBy(potion => potion.Value).ToList();
                LstPotionPurchase.ItemsSource = _purchasePotion;
                LstPotionPurchase.Items.SortDescriptions.Add(new SortDescription("Value", ListSortDirection.Ascending));
                LstPotionPurchase.Items.Refresh();
            }
            LblPotionNamePurchase.DataContext = _selectedPotionPurchase;
            LblPotionBonusPurchase.DataContext = _selectedPotionPurchase;
            LblPotionDescriptionPurchase.DataContext = _selectedPotionPurchase;
            LblPotionSellablePurchase.DataContext = _selectedPotionPurchase;
            LblPotionValuePurchase.DataContext = _selectedPotionPurchase;
        }

        private void BindPotionSell(bool reload = true)
        {
            if (reload)
            {
                _sellPotion.Clear();
                _sellPotion.AddRange(GameState.CurrentHero.GetItemsOfType(ItemType.Potion));
                _sellPotion = _sellPotion.OrderBy(potion => potion.Value).ToList();
                LstPotionSell.ItemsSource = _sellPotion;
                LstPotionSell.Items.SortDescriptions.Add(new SortDescription("SellValue", ListSortDirection.Ascending));
                LstPotionSell.Items.Refresh();
            }
            LblPotionNameSell.DataContext = _selectedPotionSell;
            LblPotionBonusSell.DataContext = _selectedPotionSell;
            LblPotionDescriptionSell.DataContext = _selectedPotionSell;
            LblPotionSellableSell.DataContext = _selectedPotionSell;
            LblPotionValueSell.DataContext = _selectedPotionSell;
        }

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Load

        /// <summary>Loads all the required data.</summary>
        private void LoadAll()
        {
            LoadAllPurchase();
            LoadAllSell();

            LblGold.DataContext = GameState.CurrentHero;
        }

        private void LoadAllPurchase() => BindPotionPurchase();

        private void LoadAllSell() => BindPotionSell();

        #endregion Load

        #region Transaction Methods

        /// <summary>Purchases selected Item.</summary>
        /// <param name="itmPurchase">Item to be purchased</param>
        /// <returns>Returns text regarding purchase</returns>
        private string Purchase(Item itmPurchase)
        {
            GameState.CurrentHero.Gold -= itmPurchase.Value;
            GameState.CurrentHero.AddItem(itmPurchase);
            LoadAllPurchase();
            LoadAllSell();
            return $"You have purchased {itmPurchase.Name} for {itmPurchase.ValueToString} gold.";
        }

        /// <summary>Sells selected Item.</summary>
        /// <param name="itmSell">Item to be sold</param>
        /// <returns>Returns text regarding sale</returns>
        private string Sell(Item itmSell)
        {
            GameState.CurrentHero.Gold += itmSell.SellValue;
            GameState.CurrentHero.RemoveItem(itmSell);
            LoadAllSell();
            return $"You have sold your {itmSell.Name} for {itmSell.SellValueToString} gold.";
        }

        #endregion Transaction Methods

        #region Purchase/Sell Button-Click Methods

        private void BtnPotionPurchase_Click(object sender, RoutedEventArgs e)
        {
            Functions.AddTextToTextBox(TxtTheGeneralStore, Purchase(_selectedPotionPurchase));
            LstPotionPurchase.UnselectAll();
        }

        private void BtnPotionSell_Click(object sender, RoutedEventArgs e)
        {
            Functions.AddTextToTextBox(TxtTheGeneralStore, Sell(_selectedPotionSell));
            LstPotionSell.UnselectAll();
            BtnPotionPurchase.IsEnabled = LstPotionPurchase.SelectedIndex >= 0 && GameState.CurrentHero.Gold >= _selectedPotionPurchase.Value;
        }

        #endregion Purchase/Sell Button-Click Methods

        #region Purchase/Sell Selection Changed

        private void LstPotionPurchase_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _selectedPotionPurchase = LstPotionPurchase.SelectedIndex >= 0
            ? (Item)LstPotionPurchase.SelectedValue
            : new Item();

            BtnPotionPurchase.IsEnabled = _selectedPotionPurchase.Value > 0 && _selectedPotionPurchase.Value <= GameState.CurrentHero.Gold;
            BindPotionPurchase(false);
        }

        private void LstPotionSell_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _selectedPotionSell = LstPotionSell.SelectedIndex >= 0 ? (Item)LstPotionSell.SelectedValue : new Item();

            BtnPotionSell.IsEnabled = _selectedPotionSell.CanSell;
            BindPotionSell(false);
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

        public TheGeneralStorePage()
        {
            InitializeComponent();
            TxtTheGeneralStore.Text =
            "你进入了杂货店，这是一个靠近市场中心的坚固的木制建筑。一个年轻漂亮的女人站在柜台后面，对你微笑。你走近她，检查她的货物。";
        }

        private void TheGeneralStorePage_OnLoaded(object sender, RoutedEventArgs e) => LoadAll();

        #endregion Page-Manipulation
    }
}