using Extensions;
using Sulimn.Classes;
using Sulimn.Views.Battle;
using System.Windows;

namespace Sulimn.Views.Exploration
{
    /// <summary>Interaction logic for MinesPage.xaml</summary>
    public partial class MinesPage
    {
        /// <summary>Has the Hero just completed a progession battle?</summary>
        internal bool Progress { get; set; }

        /// <summary>Does the Hero have more than zero health?</summary>
        /// <returns>Whether the Hero has more than zero health</returns>
        private bool Healthy()
        {
            if (GameState.CurrentHero.Statistics.CurrentHealth > 0) return true;
            Functions.AddTextToTextBox(TxtMines, "You need to heal before you can explore.");
            return false;
        }

        /// <summary>Starts a battle.</summary>
        /// <param name="progress">Will this battle be for progression?</param>
        private void StartBattle(bool progress = false)
        {
            BattlePage battlePage = new BattlePage { RefToMinesPage = this };
            battlePage.PrepareBattle("金矿", progress);
            GameState.Navigate(battlePage);
        }

        #region Button-Click Methods

        private void BtnOffices_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 20)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindGold(200, 600));
                else if (result <= 40)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindItem(250, 650));
                else if (result <= 80)
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Lion", "Crazed Miner", "Giant Bat");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Knight", "Adventurer");
                    StartBattle();
                }
            }
        }

        private void BtnOreBin_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 20)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindGold(300, 700));
                else if (result <= 40)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindItem(350, 750));
                else if (result <= 80)
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Lion", "Crazed Miner", "Giant Bat");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Knight", "Adventurer");
                    StartBattle();
                }
            }
        }

        private void BtnPumpStation_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 10)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindGold(200, 600));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindItem(250, 650));
                else if (result <= 75)
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Lion", "Crazed Miner", "Giant Bat");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Adventurer", "Gladiator", "Crazed Miner");
                    StartBattle();
                }
            }
        }

        private void BtnWorkshop_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 10)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindGold(300, 700));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtMines, GameState.EventFindItem(350, 750));
                else if (result <= 80)
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Lion", "Crazed Miner", "Giant Bat");
                    StartBattle();
                }
                else
                {
                    GameState.EventEncounterEnemy("Knight", "Adventurer", "Monk", "Gladiator");
                    StartBattle();
                }
            }
        }

        private void BtnProgress_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                GameState.DisplayNotification(
                    "These mines extend forever. You've been in here for hours in the relative dark, with only your dimming lantern to light your way, searching for whoever was working with John. You've already searched the offices, ore bin, pumping station, and the workshop.\n\n" +
                    "As you're lumbering through another seemingly endless passageway, you see a flicker of light coming from the wall as you walk past. You stop, and examine the light. It was a reflection from your lantern. It's a tiny latch! You pull the latch, and a hidden door opens!\n\n" +
                    "You enter the room that the was revealed by the hidden door, and everything is covered in a fine coat of dust. Whoever was here before hadn't been back in a long time. The room wasn't very large, but it was packed full of all sorts of things: small bits of iron, some empty barrels, some rotting wooden planks, and a small chest in the corner, slightly hidden by some planks. As you go to turn the latch, you hear something behind you.", "Sulimn");
                GameState.DisplayNotification(
                    "As you turn, you see a tough-looking man in dark priest attire. Whoever was behind these searches was obviously well-connected. Dark priests were among the most-feared people for their abilties. Few who ever faced a dark priest lived to tell the tale.\n\n" +
                    "\"So, you found it,\" said the man. \"To think, we'd been looking for weeks, and you managed to find it in less than a day! Hand over that map now or I'll be forced to take it from you,\" he continued.\n\n" +
                    "Not willing to part with what you hadn't even laid your hands on yet, you draw your sword.", "Sulimn");
                GameState.EventEncounterEnemy("Tennyson the Dark Priest");
                StartBattle(true);
            }
        }

        private void BtnBack_Click(object sender, RoutedEventArgs e) => GameState.GoBack();

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        public MinesPage()
        {
            InitializeComponent();
            TxtMines.Text =
            "你进入了废弃的矿井。这条路在入口附近分叉，有通向南、东、西的小径。附近有办公室。一个摇摇欲倒、几乎看不清的标志显示，南边的小路通向一个通向矿石仓的竖井，东边的小路通向泵站，西边的小路通向车间。";
        }

        private void MinesPage_OnLoaded(object sender, RoutedEventArgs e)
        {
            if (Progress)
            {
                Progress = false;
                GameState.DisplayNotification(
                    "你打败了黑暗牧师丁尼生。你回到箱子旁边，打开它。里面是另一张地图。旁边是满满一袋金币，总共约有5000枚金币!\n\n" +
                    "你回到黑暗牧师的身体并检查他。有些人说，黑暗牧师在死前对自己施咒，这样他们的尸体就能成为有效的“陷阱”，但你在这个例子中看不到任何证据。你发现一本写着“丁尼生”名字的小日记。大部分的书页都被他的血迹弄脏了，但有一页还清晰可辨。\n\n" +
                    $"\"店主希望我跟着这位新的冒险家, {GameState.CurrentHero.Name}, 看看他能不能找到最后一块地图。我要从他手里把剩下的拿回来给主人，作为酬谢。\"\n\n" +
                    "不管这个“老板”是谁，他肯定会让你心烦。", "苏利明");
            }
            BtnProgress.IsEnabled = GameState.CurrentHero.Level >= 20 && !GameState.CurrentHero.Progression.Mines;
        }

        #endregion Page-Manipulation Methods
    }
}