﻿using Extensions;
using Extensions.DataTypeHelpers;
using Extensions.Encryption;
using Extensions.Enums;
using Sulimn.Classes;
using Sulimn.Classes.Entities;
using Sulimn.Classes.HeroParts;
using Sulimn.Classes.Items;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Sulimn.Views.Admin
{
    /// <summary>Interaction logic for ManageUserPage.xaml</summary>
    public partial class ManageUserPage : INotifyPropertyChanged
    {
        private Hero _originalHero = new Hero();

        internal ManageUsersPage PreviousPage { get; set; }

        #region Display Manipulation

        /// <summary>Determines if buttons should be enabled.</summary>
        private void CheckInput()
        {
            //bool enabled = TxtHeroName.Text.Length > 0 && CmbClass.SelectedIndex >= 0 && TxtLevel.Text.Length > 0 &&
            //               TxtExperience.Text.Length > 0 && TxtSkillPoints.Text.Length > 0 &&
            //               TxtStrength.Text.Length > 0 && TxtVitality.Text.Length > 0 && TxtDexterity.Text.Length > 0 &&
            //               TxtWisdom.Text.Length > 0 && TxtCurrentHealth.Text.Length > 0 &&
            //               TxtMaximumHealth.Text.Length > 0 && TxtCurrentMagic.Text.Length > 0 &&
            //               TxtMaximumMagic.Text.Length > 0 && TxtGold.Text.Length > 0 && CmbWeapon.SelectedIndex >= 0 &&
            //               CmbHead.SelectedIndex >= 0 && CmbBody.SelectedIndex >= 0 && CmbHands.SelectedIndex >= 0 &&
            //               CmbLegs.SelectedIndex >= 0 && CmbFeet.SelectedIndex >= 0 &&
            //               TxtHeroName.Text != _originalHero.Name |
            //               (HeroClass)CmbClass.SelectedValue != _originalHero.Class |
            //               TxtLevel.Text != _originalHero.Level.ToString(GameState.CurrentCulture) |
            //               TxtExperience.Text != _originalHero.Experience.ToString(GameState.CurrentCulture) |
            //               TxtSkillPoints.Text != _originalHero.SkillPoints.ToString(GameState.CurrentCulture) |
            //               TxtStrength.Text != _originalHero.TotalStrength.ToString(GameState.CurrentCulture) |
            //               TxtVitality.Text != _originalHero.TotalVitality.ToString(GameState.CurrentCulture) |
            //               TxtDexterity.Text != _originalHero.TotalDexterity.ToString(GameState.CurrentCulture) |
            //               TxtWisdom.Text != _originalHero.TotalWisdom.ToString(GameState.CurrentCulture) |
            //               TxtCurrentHealth.Text != _originalHero.Statistics.CurrentHealth.ToString(GameState.CurrentCulture) |
            //               TxtCurrentMagic.Text != _originalHero.Statistics.CurrentMagic.ToString(GameState.CurrentCulture) |
            //               TxtMaximumHealth.Text != _originalHero.Statistics.MaximumHealth.ToString(GameState.CurrentCulture) |
            //               TxtMaximumMagic.Text != _originalHero.Statistics.MaximumMagic.ToString(GameState.CurrentCulture) |
            //               TxtGold.Text != _originalHero.Gold.ToString(GameState.CurrentCulture) |
            //               TxtInventory.Text != _originalHero.Inventory.ToString(GameState.CurrentCulture) |
            //               (Weapon)CmbWeapon.SelectedValue != _originalHero.Equipment.Weapon |
            //               (HeadArmor)CmbHead.SelectedValue != _originalHero.Equipment.Head |
            //               (BodyArmor)CmbBody.SelectedValue != _originalHero.Equipment.Body |
            //               (HandArmor)CmbHands.SelectedValue != _originalHero.Equipment.Hands |
            //               (LegArmor)CmbLegs.SelectedValue != _originalHero.Equipment.Legs |
            //               (FeetArmor)CmbFeet.SelectedValue != _originalHero.Equipment.Feet |
            //               (CmbLeftRing.SelectedIndex >= 0 && (Ring)CmbLeftRing.SelectedValue !=
            //                _originalHero.Equipment.LeftRing) |
            //               (CmbRightRing.SelectedIndex >= 0 && (Ring)CmbRightRing.SelectedValue !=
            //                _originalHero.Equipment.RightRing) |
            //               (PswdPassword.Password.Length > 0 && PswdConfirm.Password.Length > 0);
            //BtnSave.IsEnabled = enabled;
            //BtnReset.IsEnabled = enabled;
        }

        /// <summary>Resets input to default values.</summary>
        private void Reset()
        {
            TxtHeroName.Text = _originalHero.Name;
            ChkHardcore.IsChecked = _originalHero.Hardcore;
            TxtLevel.Text = _originalHero.Level.ToString(GameState.CurrentCulture);
            TxtExperience.Text = _originalHero.Experience.ToString(GameState.CurrentCulture);
            TxtSkillPoints.Text = _originalHero.SkillPoints.ToString(GameState.CurrentCulture);
            TxtStrength.Text = _originalHero.TotalStrength.ToString(GameState.CurrentCulture);
            TxtVitality.Text = _originalHero.TotalVitality.ToString(GameState.CurrentCulture);
            TxtDexterity.Text = _originalHero.TotalDexterity.ToString(GameState.CurrentCulture);
            TxtWisdom.Text = _originalHero.TotalWisdom.ToString(GameState.CurrentCulture);
            TxtGold.Text = _originalHero.Gold.ToString(GameState.CurrentCulture);
            TxtInventory.Text = _originalHero.Inventory.ToString();
            TxtCurrentHealth.Text = _originalHero.Statistics.CurrentHealth.ToString(GameState.CurrentCulture);
            TxtMaximumHealth.Text = _originalHero.Statistics.MaximumHealth.ToString(GameState.CurrentCulture);
            TxtCurrentMagic.Text = _originalHero.Statistics.CurrentMagic.ToString(GameState.CurrentCulture);
            TxtMaximumMagic.Text = _originalHero.Statistics.MaximumMagic.ToString(GameState.CurrentCulture);
            CmbHead.SelectedValue = _originalHero.Equipment.Head;
            CmbBody.SelectedValue = _originalHero.Equipment.Body;
            CmbHands.SelectedValue = _originalHero.Equipment.Hands;
            CmbLegs.SelectedValue = _originalHero.Equipment.Legs;
            CmbFeet.SelectedValue = _originalHero.Equipment.Feet;
            CmbLeftRing.SelectedValue = _originalHero.Equipment.LeftRing;
            CmbRightRing.SelectedValue = _originalHero.Equipment.RightRing;
            CmbWeapon.SelectedValue = _originalHero.Equipment.Weapon;
            CmbClass.SelectedValue = _originalHero.Class;
        }

        #endregion Display Manipulation

        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>Binds information to controls.</summary>
        private void BindControls()
        {
            CmbClass.ItemsSource = GameState.AllClasses;
            CmbWeapon.ItemsSource = GameState.AllWeapons;
            CmbHead.ItemsSource = GameState.AllHeadArmor;
            CmbBody.ItemsSource = GameState.AllBodyArmor;
            CmbHands.ItemsSource = GameState.AllHandArmor;
            CmbLegs.ItemsSource = GameState.AllLegArmor;
            CmbFeet.ItemsSource = GameState.AllFeetArmor;
            CmbLeftRing.ItemsSource = GameState.AllRings;
            CmbRightRing.ItemsSource = GameState.AllRings;

            Reset();
        }

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this,
            new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Input Manipulation

        private void Txt_PreviewKeyDown(object sender, KeyEventArgs e) => Functions.PreviewKeyDown(e, KeyType.Letters);

        private void TxtNumbers_PreviewKeyDown(object sender, KeyEventArgs e) => Functions.PreviewKeyDown(e, KeyType.Integers);

        private void Txt_TextChanged(object sender, TextChangedEventArgs e) => Functions.TextBoxTextChanged(sender, KeyType.Letters);

        private void Integers_TextChanged(object sender, TextChangedEventArgs e) => Functions.TextBoxTextChanged(sender, KeyType.Integers);

        private void Txt_GotFocus(object sender, RoutedEventArgs e) => Functions.TextBoxGotFocus(sender);

        private void Pswd_GotFocus(object sender, RoutedEventArgs e) => Functions.PasswordBoxGotFocus(sender);

        private void TxtInventory_PreviewKeyDown(object sender, KeyEventArgs e) => Functions.PreviewKeyDown(e, KeyType.LettersSpaceComma);

        private void TxtInventory_TextChanged(object sender, TextChangedEventArgs e) => Functions.TextBoxTextChanged(sender, KeyType.LettersSpaceComma);

        #endregion Input Manipulation

        private void Cmb_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
        }

        #region Button-Click Methods

        private void BtnSave_Click(object sender, RoutedEventArgs e)
        {
            if (TxtHeroName.Text.Length >= 4
                && ((PswdPassword.Password.Length == 0 && PswdConfirm.Password.Length == 0)
                 || (PswdPassword.Password.Length >= 4 && PswdConfirm.Password.Length >= 4))
                && PswdPassword.Password == PswdConfirm.Password)
            {
                string password = PswdPassword.Password.Length > 0
                    ? Argon2.HashPassword(PswdPassword.Password)
                    : _originalHero.Password;

                Hero newHero = new Hero(TxtHeroName.Text, password, (HeroClass)CmbClass.SelectedItem, Int32Helper.Parse(TxtLevel.Text), Int32Helper.Parse(TxtExperience.Text), Int32Helper.Parse(TxtSkillPoints.Text), Int32Helper.Parse(TxtGold.Text), new Attributes(Int32Helper.Parse(TxtStrength.Text), Int32Helper.Parse(TxtVitality.Text), Int32Helper.Parse(TxtDexterity.Text), Int32Helper.Parse(TxtWisdom.Text)), new Statistics(Int32Helper.Parse(TxtCurrentHealth.Text), Int32Helper.Parse(TxtMaximumHealth.Text), Int32Helper.Parse(TxtCurrentMagic.Text), Int32Helper.Parse(TxtMaximumMagic.Text)), new Equipment((Item)CmbWeapon.SelectedItem, (Item)CmbHead.SelectedItem, (Item)CmbBody.SelectedItem, (Item)CmbHands.SelectedItem, (Item)CmbLegs.SelectedItem, (Item)CmbFeet.SelectedItem, CmbLeftRing.SelectedIndex >= 0 ? (Item)CmbLeftRing.SelectedItem : new Item(), CmbRightRing.SelectedIndex >= 0 ? (Item)CmbRightRing.SelectedItem : new Item()), new Spellbook(_originalHero.Spellbook), GameState.SetInventory(TxtInventory.Text), new Bank(), new Progression(_originalHero.Progression), ChkHardcore.IsChecked ?? false, new List<Quest>());
                //TODO BANK
                //TODO Class isn't selected properly and won't save properly.

                if (TxtHeroName.Text != _originalHero.Name)
                {
                    Hero checkHero = GameState.AllHeroes.Find(hero => hero.Name == TxtHeroName.Text);
                    if (checkHero == null || checkHero == new Hero())
                        GameState.ChangeHeroDetails(_originalHero, newHero);
                    else
                        GameState.DisplayNotification("您试图更改的用户名已被使用，请选择另一个", "Sulimn");
                }
                else
                    GameState.SaveHero(newHero);

                ClosePage();
            }
            else if (PswdPassword.Password.Length != 0 && PswdConfirm.Password.Length != 0
                     && PswdPassword.Password.Length < 4 && PswdConfirm.Password.Length < 4)
                GameState.DisplayNotification("请确保新密码的长度为4个或更多字符", "Sulimn");
            else if (PswdPassword.Password != PswdConfirm.Password)
                GameState.DisplayNotification("请确保密码匹配", "Sulimn");
            else if (TxtHeroName.Text.Length < 4)
                GameState.DisplayNotification("请确保英雄名称和密码至少为4个字符", "Sulimn");
        }

        private void BtnReset_Click(object sender, RoutedEventArgs e) => Reset();

        private void BtnCancel_Click(object sender, RoutedEventArgs e) => ClosePage();

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            PreviousPage.RefreshItemsSource();
            GameState.GoBack();
        }

        internal void LoadPage(Hero manageHero)
        {
            _originalHero = new Hero(manageHero);
            BindControls();
        }

        public ManageUserPage() => InitializeComponent();

        #endregion Page-Manipulation Methods
    }
}