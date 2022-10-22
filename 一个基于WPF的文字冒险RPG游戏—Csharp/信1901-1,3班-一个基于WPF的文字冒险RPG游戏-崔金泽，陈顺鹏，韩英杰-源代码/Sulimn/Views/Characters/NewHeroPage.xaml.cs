﻿using Extensions;
using Extensions.Encryption;
using Extensions.Enums;
using Sulimn.Classes;
using Sulimn.Classes.Entities;
using Sulimn.Classes.HeroParts;
using Sulimn.Classes.Items;
using Sulimn.Views.Exploration;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Sulimn.Views.Characters
{
    /// <summary>Interaction logic for NewHeroPage.xaml</summary>
    public partial class NewHeroPage : INotifyPropertyChanged
    {
        public readonly List<HeroClass> _classes = new List<HeroClass>();
        private HeroClass _compareClass = new HeroClass();
        private HeroClass _selectedClass = new HeroClass();
        private bool _startGame;

        #region Display Manipulation

        /// <summary>Clears all text from the labels and resets the Page to default.</summary>
        private void Clear()
        {
            _selectedClass = new HeroClass();
            _compareClass = new HeroClass();
            LstClasses.UnselectAll();
            TxtHeroName.Clear();
            TxtHeroName.Focus();
            CheckSkillPoints();
            DisableMinus();
            TogglePlus(false);
        }

        #endregion Display Manipulation

        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Attribute Modification

        /// <summary>Increases specified Attribute.</summary>
        /// <param name="attribute">Attribute to be increased.</param>
        /// <returns>Increased attribute</returns>
        private int IncreaseAttribute(int attribute)
        {
            if (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift))
            {
                if (_selectedClass.SkillPoints >= 5)
                {
                    attribute += 5;
                    _selectedClass.SkillPoints -= 5;
                }
                else
                {
                    attribute += _selectedClass.SkillPoints;
                    _selectedClass.SkillPoints = 0;
                }
            }
            else
            {
                attribute++;
                _selectedClass.SkillPoints--;
            }

            CheckSkillPoints();
            return attribute;
        }

        /// <summary>Decreases specified Attribute.</summary>
        /// <param name="attribute">Attribute to be decreased.</param>
        /// <param name="original">Original value of the attribute for the selected class.</param>
        /// <returns>Decreased attribute</returns>
        private int DecreaseAttribute(int attribute, int original)
        {
            if (Keyboard.IsKeyDown(Key.LeftShift) || Keyboard.IsKeyDown(Key.RightShift))
            {
                if (attribute - original >= 5)
                {
                    attribute -= 5;
                    _selectedClass.SkillPoints += 5;
                }
                else
                {
                    _selectedClass.SkillPoints += attribute - original;
                    attribute -= attribute - original;
                }
            }
            else
            {
                attribute--;
                _selectedClass.SkillPoints++;
            }

            CheckSkillPoints();
            return attribute;
        }

        #endregion Attribute Modification

        #region Enable/Disable Buttons

        /// <summary>Enables/disables buttons based on the Hero's available Skill Points.</summary>
        private void CheckSkillPoints()
        {
            if (LstClasses.SelectedIndex >= 0 && _selectedClass.SkillPoints > 0)
            {
                if (_selectedClass.SkillPoints >= _compareClass.SkillPoints)
                    DisableMinus();
                TogglePlus(true);
                BtnCreate.IsEnabled = false;
            }
            else if (LstClasses.SelectedIndex >= 0 && _selectedClass.SkillPoints == 0)
            {
                TogglePlus(false);
                BtnCreate.IsEnabled = TxtHeroName.Text.Length > 0 && PswdPassword.Password.Length > 0
                && PswdConfirm.Password.Length > 0;
            }
            else if (LstClasses.SelectedIndex >= 0 && _selectedClass.SkillPoints < 0)
            {
                GameState.DisplayNotification("Somehow you have negative skill points. Please try creating your character again.",
                "Sulimn");
                Clear();
            }
        }

        #region Toggle Buttons

        /// <summary>Toggles the IsEnabled Property of the Plus Buttons.</summary>
        /// <param name="enabled">Should the Buttons be enabled?</param>
        private void TogglePlus(bool enabled)
        {
            BtnDexterityPlus.IsEnabled = enabled;
            BtnStrengthPlus.IsEnabled = enabled;
            BtnWisdomPlus.IsEnabled = enabled;
            BtnVitalityPlus.IsEnabled = enabled;
        }

        /// <summary>Disables attribute Minus Buttons.</summary>
        private void DisableMinus()
        {
            BtnDexterityMinus.IsEnabled = false;
            BtnStrengthMinus.IsEnabled = false;
            BtnWisdomMinus.IsEnabled = false;
            BtnVitalityMinus.IsEnabled = false;
        }

        #endregion Toggle Buttons

        #endregion Enable/Disable Buttons

        #region Button-Click Methods

        private void BtnCancel_Click(object sender, RoutedEventArgs e) => ClosePage();

        private void BtnCreate_Click(object sender, RoutedEventArgs e)
        {
            Hero createHero = new Hero();

            try
            {
                createHero = GameState.AllHeroes.Find(hero => hero.Name == TxtHeroName.Text);
            }
            catch (ArgumentNullException)
            {
            }
            if (!string.IsNullOrWhiteSpace(createHero?.Name))
            {
                GameState.DisplayNotification("This username has already been taken. Please choose another.", "Sulimn");
                TxtHeroName.Focus();
            }
            else
            {
                if (TxtHeroName.Text.Length >= 4 && PswdPassword.Password.Length >= 4)
                    if (PswdPassword.Password.Trim() == PswdConfirm.Password.Trim())
                    {
                        Hero newHero = new Hero(
                        TxtHeroName.Text.Trim(),
                        Argon2.HashPassword(PswdPassword.Password.Trim()),
                        _selectedClass,
                        1,
                        0,
                        0,
                        250,
                        new Attributes(
                        _selectedClass.Strength,
                        _selectedClass.Vitality,
                        _selectedClass.Dexterity,
                        _selectedClass.Wisdom),
                        new Statistics(
                        _selectedClass.CurrentHealth,
                        _selectedClass.MaximumHealth,
                        _selectedClass.CurrentMagic,
                        _selectedClass.MaximumMagic),
                        new Equipment(
                        new Item(),
                        new Item(),
                        new Item(),
                        new Item(),
                        new Item(),
                        new Item(),
                        new Item(),
                        new Item()),
                        new Spellbook(),
                        new List<Item>(),
                        new Bank(0, 0, 250),
                        new Progression(),
                        ChkHardcore.IsChecked ?? false,
                        new List<Quest>());

                        GameState.NewHero(newHero);

                        _startGame = true;
                        GameState.CurrentHero = GameState.AllHeroes.Find(hero => hero.Name == newHero.Name);
                        ClosePage();
                    }
                    else
                        GameState.DisplayNotification("Please ensure that the passwords match.", "Sulimn");
                else
                    GameState.DisplayNotification("Names and passwords have to be at least 4 characters.", "Sulimn");
            }
        }

        private void BtnReset_Click(object sender, RoutedEventArgs e) => Clear();

        #endregion Button-Click Methods

        #region Plus/Minus Button Logic

        private void BtnStrengthMinus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Strength = DecreaseAttribute(_selectedClass.Strength, _compareClass.Strength);
            BtnStrengthMinus.IsEnabled = _selectedClass.Strength != _compareClass.Strength;
        }

        private void BtnStrengthPlus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Strength = IncreaseAttribute(_selectedClass.Strength);
            BtnStrengthMinus.IsEnabled = true;
        }

        private void BtnVitalityMinus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Vitality = DecreaseAttribute(_selectedClass.Vitality, _compareClass.Vitality);
            BtnVitalityMinus.IsEnabled = _selectedClass.Vitality != _compareClass.Vitality;
        }

        private void BtnVitalityPlus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Vitality = IncreaseAttribute(_selectedClass.Vitality);
            BtnVitalityMinus.IsEnabled = true;
        }

        private void BtnDexterityMinus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Dexterity = DecreaseAttribute(_selectedClass.Dexterity, _compareClass.Dexterity);
            BtnDexterityMinus.IsEnabled = _selectedClass.Dexterity != _compareClass.Dexterity;
        }

        private void BtnDexterityPlus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Dexterity = IncreaseAttribute(_selectedClass.Dexterity);
            BtnDexterityMinus.IsEnabled = true;
        }

        private void BtnWisdomMinus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Wisdom = DecreaseAttribute(_selectedClass.Wisdom, _compareClass.Wisdom);
            BtnWisdomMinus.IsEnabled = _selectedClass.Wisdom != _compareClass.Wisdom;
        }

        private void BtnWisdomPlus_Click(object sender, RoutedEventArgs e)
        {
            _selectedClass.Wisdom = IncreaseAttribute(_selectedClass.Wisdom);
            BtnWisdomMinus.IsEnabled = true;
        }

        #endregion Plus/Minus Button Logic

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            if (_startGame)
                GameState.Navigate(new CityPage { NewHero = true });
            else
                GameState.GoBack();
        }

        public NewHeroPage()
        {
            InitializeComponent();
            _classes.AddRange(GameState.AllClasses);
            LstClasses.ItemsSource = _classes;
            DataContext = _selectedClass;
            TxtHeroName.Focus();
        }

        private void TxtHeroName_Changed(object sender, TextChangedEventArgs e)
        {
            Functions.TextBoxTextChanged(sender, KeyType.Letters);
            CheckSkillPoints();
        }

        private void TxtHeroName_GotFocus(object sender, RoutedEventArgs e) => Functions.TextBoxGotFocus(sender);

        private void TxtHeroName_PreviewKeyDown(object sender, KeyEventArgs e) => Functions.PreviewKeyDown(e,
            KeyType.Letters);

        private void Pswd_GotFocus(object sender, RoutedEventArgs e) => Functions.PasswordBoxGotFocus(sender);

        private void Pswd_Changed(object sender, RoutedEventArgs e) => CheckSkillPoints();

        private void LstClasses_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (LstClasses.SelectedIndex >= 0)
            {
                _selectedClass = new HeroClass((HeroClass)LstClasses.SelectedValue);
                _compareClass = new HeroClass((HeroClass)LstClasses.SelectedValue);
                CheckSkillPoints();
            }
            else
                Clear();

            LstClasses.ItemsSource = _classes;
            DataContext = _selectedClass;
        }

        #endregion Page-Manipulation Methods
    }
}