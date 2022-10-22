﻿using Sulimn.Classes;
using System.ComponentModel;
using System.Windows;

namespace Sulimn.Views.Battle
{
    /// <summary>Interaction logic for EnemyDetailsPage.xaml</summary>
    public partial class EnemyDetailsPage : INotifyPropertyChanged
    {
        private void BtnBack_Click(object sender, RoutedEventArgs e) => GameState.GoBack();

        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>Binds information to Page.</summary>
        private void BindLabels()
        {
            DataContext = GameState.CurrentEnemy;
            LblStrength.DataContext = GameState.CurrentEnemy.Attributes;
            LblVitality.DataContext = GameState.CurrentEnemy.Attributes;
            LblDexterity.DataContext = GameState.CurrentEnemy.Attributes;
            LblHealth.DataContext = GameState.CurrentEnemy.Statistics;
            LblGold.DataContext = GameState.CurrentEnemy;
            LblEquippedWeapon.DataContext = GameState.CurrentEnemy.Equipment.Weapon;
            LblEquippedWeaponDamage.DataContext = GameState.CurrentEnemy.Equipment.Weapon;
            LblEquippedHead.DataContext = GameState.CurrentEnemy.Equipment.Head;
            LblEquippedHeadDefense.DataContext = GameState.CurrentEnemy.Equipment.Head;
            LblEquippedBody.DataContext = GameState.CurrentEnemy.Equipment.Body;
            LblEquippedBodyDefense.DataContext = GameState.CurrentEnemy.Equipment.Body;
            LblEquippedLegs.DataContext = GameState.CurrentEnemy.Equipment.Legs;
            LblEquippedLegsDefense.DataContext = GameState.CurrentEnemy.Equipment.Legs;
            LblEquippedFeet.DataContext = GameState.CurrentEnemy.Equipment.Feet;
            LblEquippedFeetDefense.DataContext = GameState.CurrentEnemy.Equipment.Feet;
        }

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>

        public EnemyDetailsPage()
        {
            InitializeComponent();
            BindLabels();
        }

        #endregion Page-Manipulation Methods
    }
}