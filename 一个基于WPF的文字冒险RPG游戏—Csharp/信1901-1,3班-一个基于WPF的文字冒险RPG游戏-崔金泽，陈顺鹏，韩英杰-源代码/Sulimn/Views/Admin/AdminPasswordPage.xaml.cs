﻿using Extensions.Encryption;
using Sulimn.Classes;
using System.Windows;

namespace Sulimn.Views.Admin
{
    /// <summary>Interaction logic for AdminPasswordPage.xaml</summary>
    public partial class AdminPasswordPage
    {
        private bool _admin;

        #region Button-Click Methods

        private void BtnSubmit_Click(object sender, RoutedEventArgs e)
        {
            if (Argon2.ValidatePassword(GameState.CurrentSettings.AdminPassword, PswdAdmin.Password))
            {
                _admin = true;
                ClosePage();
            }
            else
            {
                GameState.DisplayNotification("登录不合法.", "Sulimn");
                PswdAdmin.SelectAll();
            }
        }

        private void BtnCancel_Click(object sender, RoutedEventArgs e) => ClosePage();

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            GameState.GoBack();
            if (_admin)
                GameState.Navigate(new AdminPage());
            else
                GameState.MainWindow.MnuAdmin.IsEnabled = true;
        }

        public AdminPasswordPage()
        {
            InitializeComponent();
            PswdAdmin.Focus();
        }

        private void TxtPassword_PasswordChanged(object sender, RoutedEventArgs e) => BtnSubmit.IsEnabled = PswdAdmin.Password.Length > 0;

        #endregion Page-Manipulation Methods
    }
}