﻿using Extensions;
using Sulimn.Classes;
using System.Windows;

namespace Sulimn.Views.Exploration
{
    /// <summary>Interaction logic for CatacombsPage.xaml</summary>
    public partial class CatacombsPage
    {
        /// <summary>Has the Hero just completed a progession battle?</summary>
        internal bool Progress { get; set; }

        /// <summary>Does the Hero have more than zero health?</summary>
        /// <returns>Whether the Hero has more than zero health</returns>
        private bool Healthy()
        {
            if (GameState.CurrentHero.Statistics.CurrentHealth > 0) return true;
            Functions.AddTextToTextBox(TxtCatacombs, "在你探索之前，你需要疗伤。");
            return false;
        }

        /// <summary>Starts a battle.</summary>
        /// <param name="progress">Will this battle be for progression?</param>
        private void StartBattle(bool progress = false)
        {
            Battle.BattlePage battlePage = new Battle.BattlePage { RefToCatacombsPage = this, };
            battlePage.PrepareBattle("地下墓穴", progress);
            GameState.Navigate(battlePage);
        }

        #region Button-Click Methods

        private void BtnCrypts_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 20)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindGold(400, 800));
                else if (result <= 40)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindItem(500, 1000));
                else
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Necromancer", "Priest", "Dark Priest", "Adventurer",
                    "Knight", "Minotaur", "Evil Knight", "Giant Bat");
                    StartBattle();
                }
            }
        }

        private void BtnShantytown_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 15)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindGold(50, 200));
                else if (result <= 30)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindItem(100, 300));
                else
                {
                    GameState.EventEncounterEnemy("Beggar", "Thief", "Butcher", "Squire", "Adventurer", "Knave",
                    "Mangy Dog");
                    StartBattle();
                }
            }
        }

        private void BtnRavine_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 5)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindGold(400, 800));
                else if (result <= 20)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindItem(500, 1000));
                else
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Necromancer", "Priest", "Dark Priest", "Adventurer",
                    "Knight", "Minotaur", "Evil Knight", "Giant Bat", "Mangy Dog");
                    StartBattle();
                }
            }
        }

        private void BtnAqueduct_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                int result = Functions.GenerateRandomNumber(1, 100);
                if (result <= 5)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindGold(450, 900));
                else if (result <= 20)
                    Functions.AddTextToTextBox(TxtCatacombs, GameState.EventFindItem(500, 1000));
                else
                {
                    GameState.EventEncounterEnemy("Giant Spider", "Necromancer", "Priest", "Dark Priest", "Adventurer",
                    "Knight", "Minotaur", "Evil Knight", "Giant Bat", "Mangy Dog");
                    StartBattle();
                }
            }
        }

        private void BtnProgress_Click(object sender, RoutedEventArgs e)
        {
            if (Healthy())
            {
                GameState.DisplayNotification(
                    "After hours of carefully following the map's path through the catacombs, you reach a large stone door. You attempt to pull at it, but it won't budge. It has to be locked from the other side. You backtrack a way, but can't find a way to get inside the room. You return to it and have no choice but to knock.\n\n" +
                    "The knocking echoes through the catacombs, despite you not knocking very loud. You hear sounds coming from the other side of the door; the door was being unlatched. As it opens, you peer into the room and are surprised to see that it is very tall, much taller than the catacombs corridors you've been going down. It is sparsely furnished, the main attraction being an altar at the center of the room, surrounded by several candles. This place is clearly a chapel of some kind, possibly the home to some of the necromancers you've been fighting.\n\n" +
                    "As you step inside, the person who opened the door, a tall, hooded figure in dark robes, walks from behind the door toward the altar, and two more figures emerge and walk toward the altar. It is definitely a necromancer sanctuary. The shorter of the three points a finger at you, and speaks in a surprisingly feminine voice,\n\n" +
                    "\"We've been expecting your arrival. Are you prepared for the sacrifice?\"", "Sulimn"); GameState.DisplayNotification(
                    "Sacrifice? You didn't know anything about a sacrifice. You didn't know what to expect when you came down here. You shake your head unknowingly.\n\n" +
                    "\"Then you shall become the sacrifice!\", she yells.\n" +
                    "\"You dare to come into our domain without knowledge of the sacrifice? You dare to defy Dion, the Necromancer Priestess? You shall be punished!\" she screamed, raising her staff to point at you.", "Sulimn");
                GameState.EventEncounterEnemy("Dion the Necromancer");
                StartBattle(true);
            }
        }

        private void BtnBack_Click(object sender, RoutedEventArgs e) => GameState.GoBack();

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        public CatacombsPage()
        {
            InitializeComponent();
            TxtCatacombs.Text =
            "You find the entrance to the catacombs, a long series of underground passages created throughout the last several hundred years. Thousands of people were buried here in crypts. You've heard of a shantytown down here, a place for the less fortunate to sleep at night. There is also supposed to be a large ravine down here to explore. Also, an ancient aqueduct system runs beneath the city, transporting water all over the city.";
        }

        private void CatacombsPage_OnLoaded(object sender, RoutedEventArgs e)
        {
            if (Progress)
            {
                Progress = false;
                GameState.DisplayNotification(
                    "You have defeated Dion the Necromancer. As she falls to the floor, her necromancer minions flee the room like the cowards they are. You examine the room in further detail, and discover a hidden compartment under the altar. In it is a note and ring with a gem of many colors. The note reads,\n\n" +
                    "\"You have done well, Dion. Once we have completed the sacrifice, nothing with be able to stop us! The kingdom will be ours for the taking, my love!\"\n\n" +
                    "You pocket the note and the ring, and realize that whoever is behind this is inside the castle. You must foil the plot and ensure the freedom of this kingdom's citizens!", "Sulimn");
            }
            BtnProgress.IsEnabled = GameState.CurrentHero.Level >= 25 && !GameState.CurrentHero.Progression.Catacombs;
        }

        #endregion Page-Manipulation Methods
    }
}