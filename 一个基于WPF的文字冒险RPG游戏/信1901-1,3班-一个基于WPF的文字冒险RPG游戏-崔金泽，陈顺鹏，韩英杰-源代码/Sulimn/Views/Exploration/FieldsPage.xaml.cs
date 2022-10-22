using Extensions;
using Sulimn.Classes;
using Sulimn.Views.Battle;
using System.Windows;

namespace Sulimn.Views.Exploration
{
    /// <summary>Interaction logic for FieldsPage.xaml</summary>
    public partial class FieldsPage
    {
        /// <summary>Has the Hero just completed a progession battle?</summary>
        internal bool Progress { get; set; }

        /// <summary>Does the Hero have more than zero health?</summary>
        /// <returns>Whether the Hero has more than zero health</returns>
        private bool Healthy()
        {
            if (GameState.CurrentHero.Statistics.CurrentHealth > 0) return true;
            Functions.AddTextToTextBox(TxtFields, "在你探索之前，你需要疗伤。");
            return false;
        }

        /// <summary>Starts a battle.</summary>
        /// <param name="progress">Will this battle be for progression?</param>
        private void StartBattle(bool progress = false)
        {
            BattlePage battlePage = new BattlePage { RefToFieldsPage = this };
            battlePage.PrepareBattle("田野", progress);
            GameState.Navigate(battlePage);
        }

        #region Button-Click Methods

        private void BtnFarm_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 15)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindGold(1, 100));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindItem(1, 200));
                else if (result <= 65)
                {
                    GameState.EventEncounterAnimal(1, 3);
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy(1, 3);
                    StartBattle();
                }
            }
        }

        private void BtnCellar_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 15)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindGold(1, 150));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindItem(1, 250));
                else if (result <= 80)
                {
                    GameState.EventEncounterEnemy("Rabbit", "Snake");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Beggar", "Thief");
                    StartBattle();
                }
            }
        }

        private void BtnCropFields_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 5)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindGold(25, 200));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindItem(1, 300));
                else if (result <= 65)
                {
                    GameState.EventEncounterEnemy("Rabbit", "Snake", "Mangy Dog", "Chicken");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Thief");
                    StartBattle();
                }
            }
        }

        private void BtnOrchard_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 15)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindGold(50, 250));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtFields, GameState.EventFindItem(1, 350));
                else if (result <= 80)
                {
                    GameState.EventEncounterEnemy("Rabbit", "Snake", "Mangy Dog", "Chicken");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Beggar", "Thief", "Knave");
                    StartBattle();
                }
            }
        }

        private void BtnProgress_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                GameState.DisplayNotification(
                    "You feel a presence behind you and turn to look. A Knave stands at the ready. He calls out to you,\n\n" +
                    "\"I've been watching your progress fighting these wild animals and weaklings. You show promise. However, you'll never make it to the Forest in time to stop what we're planning. It's a pity that I, Leon, have to kill you now.\"\n\n" +
                    "With that, he draws his sword and rushes at you. You prepare your defense.", "Sulimn");
                GameState.EventEncounterEnemy("Leon the Knave");
                StartBattle(true);
            }
        }

        private void BtnBack_Click(object sender, RoutedEventArgs e) => GameState.GoBack();

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        public FieldsPage()
        {
            InitializeComponent();
            TxtFields.Text = "你进入农田，朝农田走去。在路上，你看到一个废弃的农舍，杂草丛生，藤蔓丛生。你在一堵摇摇欲坠的石墙前停下脚步，这堵石墙曾经是它的地界，然后你看到一扇杂草丛生的门通向一个地窖。在远处，你看到一个果园。";
        }

        private void FieldsPage_OnLoaded(object sender, RoutedEventArgs e)
        {
            if (Progress)
            {
                Progress = false;
                GameState.DisplayNotification("你打败了杰克里昂。当你翻找他的遗物时，你发现了一张粗略绘制的地图，上面显示了城镇外森林深处的一个位置。你把地图藏在你的袋子里，记住这个位置当你有足够的力量去面对潜伏在那里的人。", "苏利明");
            }
            BtnProgress.IsEnabled = GameState.CurrentHero.Level >= 5 && !GameState.CurrentHero.Progression.Fields;
        }

        #endregion Page-Manipulation Methods
    }
}