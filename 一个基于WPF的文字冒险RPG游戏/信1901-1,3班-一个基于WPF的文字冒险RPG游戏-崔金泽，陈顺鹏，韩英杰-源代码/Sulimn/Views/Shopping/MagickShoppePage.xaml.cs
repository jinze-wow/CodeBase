using Extensions;
using Sulimn.Classes;
using Sulimn.Classes.HeroParts;
using Sulimn.Views.Characters;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Windows;
using System.Windows.Controls;

namespace Sulimn.Views.Shopping
{
    /// <summary>Interaction logic for YeOldeMagickShoppePage.xaml</summary>
    public partial class MagickShoppePage : INotifyPropertyChanged
    {
        private List<Spell> _purchasableSpells = new List<Spell>();
        private Spell _selectedSpell = new Spell();

        /// <summary>Loads all the required data.</summary>
        private void LoadAll()
        {
            BindLabels();
            _purchasableSpells.Clear();
            _purchasableSpells.AddRange(GameState.AllSpells);
            List<Spell> learnSpells = new List<Spell>();

            foreach (Spell spell in _purchasableSpells)
            {
                if (!GameState.CurrentHero.Spellbook.Spells.Contains(spell))
                {
                    if (spell.AllowedClasses.Count == 0)
                        learnSpells.Add(spell);
                    else if (spell.AllowedClasses.Contains(GameState.CurrentHero.Class))
                        learnSpells.Add(spell);
                }
            }

            _purchasableSpells.Clear();
            _purchasableSpells = learnSpells.OrderBy(x => x.Name).ToList();
            LstSpells.ItemsSource = _purchasableSpells;
            LstSpells.Items.SortDescriptions.Add(new SortDescription("Value", ListSortDirection.Ascending));
        }

        #region Data-Binding

        public event PropertyChangedEventHandler PropertyChanged;

        private void BindLabels()
        {
            DataContext = _selectedSpell;
            LblGold.DataContext = GameState.CurrentHero;
        }

        protected void NotifyPropertyChanged(string property) => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(property));

        #endregion Data-Binding

        #region Click Methods

        private void BtnPurchase_Click(object sender, RoutedEventArgs e)
        {
            GameState.CurrentHero.Gold -= _selectedSpell.Value;
            Functions.AddTextToTextBox(TxtMagickShoppe, $"{GameState.CurrentHero.Spellbook.LearnSpell(_selectedSpell)} It cost {_selectedSpell.ValueToString} gold.");
            LoadAll();
        }

        private void BtnCharacter_Click(object sender, RoutedEventArgs e) => GameState.Navigate(new CharacterPage());

        private void BtnBack_Click(object sender, RoutedEventArgs e) => ClosePage();

        private void LstSpells_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            _selectedSpell = LstSpells.SelectedIndex >= 0 ? (Spell)LstSpells.SelectedValue : new Spell();

            BtnPurchase.IsEnabled = _selectedSpell.Value > 0 && _selectedSpell.Value <= GameState.CurrentHero.Gold && _selectedSpell.MinimumLevel <= GameState.CurrentHero.Level;
            BindLabels();
        }

        #endregion Click Methods

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            GameState.SaveHero(GameState.CurrentHero);
            GameState.GoBack();
        }

        public MagickShoppePage()
        {
            InitializeComponent();
            TxtMagickShoppe.Text =
            "你进入了魔法屋,一个小屋式的建筑。里面有个女人背对着你，在锅里搅拌着混合物。她察觉到你的存在，转向你，她的脸丑陋不堪，满是疖子。\n\n" +
            $"\"你想学习一些咒语吗，, {GameState.CurrentHero.Name}?\" 她问。你不明白她是怎么知道你的名字的。";
        }

        private void MagickShoppePage_OnLoaded(object sender, RoutedEventArgs e) => LoadAll();

        #endregion Page-Manipulation Methods
    }
}