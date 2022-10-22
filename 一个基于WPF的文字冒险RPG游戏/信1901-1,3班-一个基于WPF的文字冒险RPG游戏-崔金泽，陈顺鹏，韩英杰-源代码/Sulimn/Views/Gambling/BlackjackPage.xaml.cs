using Extensions;
using Extensions.DataTypeHelpers;
using Extensions.Enums;
using Sulimn.Classes;
using Sulimn.Classes.Card;
using Sulimn.Classes.Enums;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace Sulimn.Views.Gambling
{
    /// <summary>Interaction logic for BlackjackPage.xaml</summary>
    public partial class BlackjackPage : INotifyPropertyChanged
    {
        private Hand MainHand = new Hand(), SplitHand = new Hand(), DealerHand = new Hand();
        private bool _handOver = true;
        private int _index, _mainBet, _splitBet, _sidePot, _totalWins, _totalLosses, _totalDraws, _totalBetWinnings, _totalBetLosses;

        private readonly List<Card> CardList = new List<Card>();
        private bool mainHandOver = true;
        private bool splitHandOver = true;

        #region Properties

        /// <summary>Is the Main Hand over?</summary>
        public bool MainHandOver
        {
            get => mainHandOver;
            set { mainHandOver = value; NotifyPropertyChanged(nameof(MainHandOver)); }
        }

        /// <summary>Is the Split Hand over?</summary>
        public bool SplitHandOver
        {
            get => splitHandOver;
            set { splitHandOver = value; NotifyPropertyChanged(nameof(SplitHandOver)); }
        }

        /// <summary>Is the round over?</summary>
        public bool RoundOver => MainHandOver && SplitHandOver;

        /// <summary>Current bet for the main hand.</summary>
        public int MainBet
        {
            get => _mainBet;
            set { _mainBet = value; NotifyPropertyChanged(nameof(MainBet)); }
        }

        /// <summary>Current bet for the split hand.</summary>
        public int SplitBet
        {
            get => _splitBet;
            set { _splitBet = value; NotifyPropertyChanged(nameof(SplitBet)); }
        }

        /// <summary>Current insurance bet.</summary>
        public int SidePot
        {
            get => _sidePot;
            set { _sidePot = value; NotifyPropertyChanged(nameof(SidePot)); }
        }

        /// <summary>Total wins for the player.</summary>
        public int TotalWins
        {
            get => _totalWins;
            set
            {
                _totalWins = value;
                NotifyPropertyChanged(nameof(TotalWins), nameof(Statistics));
            }
        }

        /// <summary>Total losses for the player.</summary>
        public int TotalLosses
        {
            get => _totalLosses;
            set
            {
                _totalLosses = value;
                NotifyPropertyChanged(nameof(TotalLosses), nameof(Statistics));
            }
        }

        /// <summary>Total draws.</summary>
        public int TotalDraws
        {
            get => _totalDraws;
            set
            {
                _totalDraws = value;
                NotifyPropertyChanged(nameof(TotalDraws), nameof(Statistics));
            }
        }

        /// <summary>Total bet winnings for the player.</summary>
        public int TotalBetWinnings
        {
            get => _totalBetWinnings;
            set
            {
                _totalBetWinnings = value;
                NotifyPropertyChanged(nameof(TotalBetWinnings), nameof(Statistics));
            }
        }

        /// <summary>Total bet losses for the player.</summary>
        public int TotalBetLosses
        {
            get => _totalBetLosses;
            set
            {
                _totalBetLosses = value;
                NotifyPropertyChanged(nameof(TotalBetLosses), nameof(Statistics));
            }
        }

        /// <summary>Statistics about the player's games.</summary>
        public string Statistics => $"Wins: {TotalWins:N0}\n" +
        $"Losses: {TotalLosses:N0}\n" +
        $"Draws: {TotalDraws:N0}\n" +
        $"Gold Won: {TotalBetWinnings:N0}\n" +
        $"Gold Lost: {TotalBetLosses:N0}";

        #endregion Properties

        /// <summary>Action taking place on the Dealer's turn.</summary>
        private void DealerAction()
        {
            bool keepGoing = true;

            while (keepGoing)
                if (DealerHand.ActualValue == 21)
                { keepGoing = false; }
                else if (DealerHand.ActualValue >= 17)
                {
                    if (DealerHand.ActualValue > 21 && DealerHand.HasAceEleven())
                        ConvertAce(DealerHand);
                    else
                        keepGoing = false;
                }
                else
                    DealCard(DealerHand);
            DealerHand.ClearHidden();
        }

        #region INotifyPropertyChanged Members

        /// <summary>The event that is raised when a property that calls the NotifyPropertyChanged method is changed.</summary>
        public event PropertyChangedEventHandler PropertyChanged;

        /// <summary>Raises the PropertyChanged event alerting the WPF Framework to update the UI.</summary>
        /// <param name="propertyNames">The names of the properties to update in the UI.</param>
        protected void NotifyPropertyChanged(params string[] propertyNames)
        {
            if (PropertyChanged != null)
            {
                foreach (string propertyName in propertyNames)
                {
                    PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
                }
            }
        }

        /// <summary>Raises the PropertyChanged event alerting the WPF Framework to update the UI.</summary>
        /// <param name="propertyName">The optional name of the property to update in the UI. If this is left blank, the name will be taken from the calling member via the CallerMemberName attribute.</param>
        protected virtual void NotifyPropertyChanged([CallerMemberName]string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        /// <summary>Binds information to controls.</summary>
        private void BindLabels()
        {
            DataContext = this;
            LstMain.ItemsSource = MainHand.CardList;
            LstMain.Items.Refresh();
            LstSplit.ItemsSource = SplitHand.CardList;
            LstSplit.Items.Refresh();
            LstDealer.ItemsSource = DealerHand.CardList;
            LstDealer.Items.Refresh();
            LblMainTotal.DataContext = MainHand;
            LblSplitTotal.DataContext = SplitHand;
            LblDealerTotal.DataContext = DealerHand;
            LblGold.DataContext = GameState.CurrentHero;
        }

        #endregion INotifyPropertyChanged Members

        #region Check Logic

        /// <summary>Checks whether the Dealer has an Ace face up.</summary>
        /// <returns>Returns true if the Dealer has an Ace face up.</returns>
        private bool CheckInsurance() => !MainHandOver && DealerHand.CardList[0].Value == 11 && SidePot == 0;

        #endregion Check Logic

        #region Display

        private void DisplayHands()
        {
            DisplayDealerHand();
            BindLabels();
        }

        private void DisplayDealerHand()
        {
            if (MainHandOver && SplitHandOver)
                DealerHand.ClearHidden();

            LblDealerTotal.Text = DealerHand.TotalValue > 0 ? DealerHand.Value : "";
        }

        #endregion Display

        #region Button Management

        /// <summary>Checks which Buttons should be enabled.</summary>
        private void CheckButtons()
        {
            ToggleMainHandButtons(MainHand.ActualValue < 21 && !MainHandOver);
            BtnConvertAce.IsEnabled = MainHand.HasAceEleven();
            ToggleSplitHandButtons(SplitHand.ActualValue < 21 && !SplitHandOver);
            BtnConvertAceSplit.IsEnabled = SplitHand.HasAceEleven() && !SplitHandOver;
        }

        /// <summary>Disables all the buttons on the Page except for BtnDealHand.</summary>
        private void DisablePlayButtons()
        {
            ToggleNewGameExitButtons(true);
            ToggleMainHandButtons(false);
            ToggleSplitHandButtons(false);
            BtnConvertAce.IsEnabled = false;
            BtnConvertAceSplit.IsEnabled = false;
        }

        private void ToggleNewGameExitButtons(bool enabled)
        {
            BtnDealHand.IsEnabled = enabled;
            BtnReturn.IsEnabled = enabled;
        }

        /// <summary>Toggles the Hit and Stay Buttons' IsEnabled property.</summary>
        /// <param name="enabled">Should the Buttons be enabled?</param>
        private void ToggleMainHandButtons(bool enabled)
        {
            BtnHit.IsEnabled = enabled;
            BtnStay.IsEnabled = enabled;
            BtnDoubleDown.IsEnabled = MainHand.CanDoubleDown();
        }

        /// <summary>Toggles the Split Hand's Hit and Stay Buttons' Enabled property.</summary>
        /// <param name="enabled">Should the Buttons be enabled?</param>
        private void ToggleSplitHandButtons(bool enabled)
        {
            BtnHitSplit.IsEnabled = enabled;
            BtnStaySplit.IsEnabled = enabled;
            BtnDoubleDownSplit.IsEnabled = SplitHand.CanDoubleDown();
        }

        #endregion Button Management

        #region Card Management

        /// <summary>Converts the first Ace valued at eleven in the Hand to be valued at one.</summary>
        /// <param name="handConvert">Hand to be converted.</param>
        private void ConvertAce(Hand handConvert)
        {
            handConvert.ConvertAce();
            CheckButtons();
            BindLabels();
            DisplayHands();
        }

        /// <summary>Creates a deck of Cards.</summary>
        /// <param name="numberOfDecks">Number of standard-sized decks to add to total deck.</param>
        private void CreateDeck(int numberOfDecks)
        {
            CardList.Clear();
            for (int h = 0; h < numberOfDecks; h++)
                for (int i = 1; i < 14; i++)
                    for (int j = 0; j < 4; j++)
                    {
                        string name;
                        CardSuit suit = CardSuit.Spades;
                        int value;

                        switch (j)
                        {
                            case 0:
                                suit = CardSuit.Spades;
                                break;

                            case 1:
                                suit = CardSuit.Hearts;
                                break;

                            case 2:
                                suit = CardSuit.Clubs;
                                break;

                            case 3:
                                suit = CardSuit.Diamonds;
                                break;
                        }

                        switch (i)
                        {
                            case 1:
                                name = "Ace";
                                value = 11;
                                break;

                            case 11:
                                name = "Jack";
                                value = 10;
                                break;

                            case 12:
                                name = "Queen";
                                value = 10;
                                break;

                            case 13:
                                name = "King";
                                value = 10;
                                break;

                            default:
                                name = i.ToString();
                                value = i;
                                break;
                        }

                        Card newCard = new Card(name, suit, value, false);
                        CardList.Add(newCard);
                    }
        }

        /// <summary>Deals a Card to a specific Hand.</summary>
        /// <param name="handAdd">Hand where Card is to be added.</param>
        /// <param name="hidden">Should the Card be hidden?</param>
        private void DealCard(Hand handAdd, bool hidden = false)
        {
            handAdd.AddCard(new Card(CardList[_index], hidden));
            _index++;
        }

        /// <summary>Creates a new Hand for both the Player and the Dealer.</summary>
        private void DealHand()
        {
            // make all hands empty.
            // reset handOver and DoubledDown
            // make the bet LineEdit uneditable.
            // Check insurance
            // disable exit buttons
            // if current spot in deck is at 20% of total cards, reshuffle
            // deal cards
            // check can split
            // display cards, enable play buttons

            MainHand = new Hand();
            SplitHand = new Hand();
            DealerHand = new Hand();

            SplitBet = 0;
            SidePot = 0;

            MainHandOver = false;
            SplitHandOver = true;
            PnlSplit.Visibility = Visibility.Hidden;

            TxtBet.IsEnabled = false;
            TxtInsurance.Text = "";
            ToggleNewGameExitButtons(false);
            if (_index >= CardList.Count * 0.8)
            {
                _index = 0;
                CardList.Shuffle();
            }

            DealCard(MainHand);
            DealCard(DealerHand);
            DealCard(MainHand);
            DealCard(DealerHand, true);
            if (MainHand.CanSplit())
                BtnSplit.IsEnabled = true;
            DisplayHands();
            CheckWinConditions();
            ToggleInsurance(CheckInsurance());
        }

        /// <summary>Toggles the Insurance controls.</summary>
        /// <param name="enabled">Should the controls be enabled?</param>
        private void ToggleInsurance(bool enabled)
        {
            TxtInsurance.IsEnabled = enabled;
            BtnInsurance.IsEnabled = TxtInsurance.IsEnabled && TxtInsurance.Text.Length > 0;
        }

        #endregion Card Management

        #region Game Results

        /// <summary>The game ends in a draw.</summary>
        private string DrawBlackjack()
        {
            EndHand();
            TotalDraws++;
            return " You reach a draw.";
        }

        /// <summary>Ends the Hand.</summary>
        private void EndHand()
        {
            TxtBet.IsEnabled = true;
            DisablePlayButtons();
            DisplayStatistics();
            BindLabels();
        }

        /// <summary>Displays the game's statistics.</summary>
        private void DisplayStatistics() => LblStatistics.Text = Statistics;

        /// <summary>The game ends with the Player losing.</summary>
        /// <param name="betAmount">Amount the Player bet</param>
        private string LoseBlackjack(int betAmount)
        {
            GameState.CurrentHero.Gold -= betAmount;
            TotalLosses++;
            TotalBetLosses += betAmount;
            EndHand();
            return $" You lose {betAmount:N0}.";
        }

        /// <summary>The game ends with the Player winning.</summary>
        /// <param name="betAmount">Amount the Player bet</param>
        private string WinBlackjack(int betAmount)
        {
            GameState.CurrentHero.Gold += betAmount;
            TotalWins++;
            TotalBetWinnings += betAmount;
            EndHand();
            return $" You win {betAmount}!";
        }

        #endregion Game Results

        /// <summary>Determines whether the round is over.</summary>
        private void CheckWinConditions()
        {
            if (MainHandOver && SplitHandOver)
            {
                ToggleMainHandButtons(false);
                ToggleSplitHandButtons(false);
                ToggleInsurance(false);
                // check whether or not the dealer needs to take any action
                // I do not recognize the dealer winning with Five Card Charlie, as it's a house rule, anyway. Only the player can win with it.
                // when I try to merge or invert these if statements, it doesn't work right. VS must not have the right operator precendence.
                if (MainHand.HasBlackjack() && SplitHand.HasBlackjack())
                { }
                else if (MainHand.IsBust() && SplitHand.IsBust())
                { }
                else if (SplitHand.Count == 0 && (MainHand.HasBlackjack() || MainHand.IsBust() || MainHand.HasFiveCardCharlie()))
                { }
                else if ((MainHand.HasBlackjack() && SplitHand.IsBust()) || (MainHand.IsBust() && SplitHand.HasBlackjack()))
                { }
                else if (MainHand.HasFiveCardCharlie() && (SplitHand.IsBust() || SplitHand.HasBlackjack()))
                { }
                else
                    DealerAction();

                if (MainHand.IsBust())
                    Functions.AddTextToTextBox(TxtBlackjack, "你的主牌打光了！" + LoseBlackjack(MainBet));
                else if (MainHand.HasBlackjack() && MainHand.Count == 2)
                {
                    if (DealerHand.ActualValue != 21)
                        Functions.AddTextToTextBox(TxtBlackjack, "你的主牌是天生的二十一点!" + WinBlackjack(Int32Helper.Parse(MainBet * 1.5)));
                    else
                    {
                        Functions.AddTextToTextBox(TxtBlackjack, "你的主牌和发牌人都有天然的二十一点。" + DrawBlackjack());
                    }
                }
                else if (DealerHand.IsBust())
                    Functions.AddTextToTextBox(TxtBlackjack, "商店卖空了!" + WinBlackjack(MainBet));
                else if (MainHand.HasBlackjack() && (DealerHand.IsBust() || DealerHand.ActualValue < 21))
                    Functions.AddTextToTextBox(TxtBlackjack, "你的主牌是21！" + WinBlackjack(MainBet));
                else if (MainHand.HasFiveCardCharlie())
                {
                    if (!DealerHand.HasBlackjack() || DealerHand.Count != 2)
                    {
                        Functions.AddTextToTextBox(TxtBlackjack, "你的主牌是一张五牌查理！" + WinBlackjack(MainBet));
                    }
                    else
                        Functions.AddTextToTextBox(TxtBlackjack, "你的主牌是一张五牌查理，但是发牌人有一张天然的二十一点。" + DrawBlackjack());
                }
                else if (MainHand.ActualValue > DealerHand.ActualValue && !DealerHand.IsBust())
                    Functions.AddTextToTextBox(TxtBlackjack, "你主手牌的牌值大于发牌人的牌值。" + WinBlackjack(MainBet));
                else if (MainHand.ActualValue == DealerHand.ActualValue)
                    Functions.AddTextToTextBox(TxtBlackjack, "你主手牌的牌值与发牌人的牌值相同。" + DrawBlackjack());
                else if (MainHand.ActualValue < DealerHand.ActualValue)
                    Functions.AddTextToTextBox(TxtBlackjack, "你主牌的牌值低于发牌人的牌值。" + LoseBlackjack(MainBet));

                //check split hand
                if (SplitHand.Count != 0)
                {
                    if (SplitHand.IsBust())
                        Functions.AddTextToTextBox(TxtBlackjack, "你的手牌打完了！" + LoseBlackjack(SplitBet));
                    else if (SplitHand.HasBlackjack() && SplitHand.Count == 2)
                    {
                        if (DealerHand.ActualValue != 21)
                            Functions.AddTextToTextBox(TxtBlackjack, "你的手牌是天生的二十一点！" + WinBlackjack(Int32Helper.Parse(SplitBet * 1.5)));
                        else
                        {
                            Functions.AddTextToTextBox(TxtBlackjack, "你的手牌和发牌人都有二十一点。" + DrawBlackjack());
                        }
                    }
                    else if (DealerHand.IsBust())
                        Functions.AddTextToTextBox(TxtBlackjack, "商店已经空了!" + WinBlackjack(SplitBet));
                    else if (SplitHand.HasBlackjack() && (DealerHand.IsBust() || DealerHand.ActualValue < 21))
                        Functions.AddTextToTextBox(TxtBlackjack, "你的手牌是21点!" + WinBlackjack(SplitBet));
                    else if (SplitHand.HasFiveCardCharlie())
                    {
                        if (!DealerHand.HasBlackjack() || DealerHand.Count != 2)
                        {
                            Functions.AddTextToTextBox(TxtBlackjack, "你的分牌是五牌查理!" + WinBlackjack(SplitBet));
                        }
                        else
                            Functions.AddTextToTextBox(TxtBlackjack, "你的分牌是五牌查理，但发牌人有天然的二十一点。" + DrawBlackjack());
                    }
                    else if (SplitHand.ActualValue > DealerHand.ActualValue && !DealerHand.IsBust())
                        Functions.AddTextToTextBox(TxtBlackjack, "你那张被分开的牌比发牌人的牌值大。" + WinBlackjack(SplitBet));
                    else if (SplitHand.ActualValue == DealerHand.ActualValue)
                        Functions.AddTextToTextBox(TxtBlackjack, "你分出的手牌和发牌人的牌值一样。" + DrawBlackjack());
                    else if (SplitHand.ActualValue < DealerHand.ActualValue)
                        Functions.AddTextToTextBox(TxtBlackjack, "你那张被分开的牌比发牌人的牌值少。" + LoseBlackjack(SplitBet));
                }

                //check side pot
                if (SidePot > 0 && DealerHand.Count == 2 && DealerHand.HasBlackjack())
                    Functions.AddTextToTextBox(TxtBlackjack, "你的保险已经偿付了!" + WinBlackjack(SidePot));
                else if (SidePot > 0)
                    Functions.AddTextToTextBox(TxtBlackjack, "你的保险没有偿付。" + LoseBlackjack(SidePot));
            }

            if (!MainHandOver)
            {
                if (MainHand.HasBlackjack() || MainHand.IsBust() || (MainHand.Count == 5 && (MainHand.ActualValue < 21 || (MainHand.HasAceEleven() && MainHand.ActualValue <= 31))))
                {
                    MainHandOver = true;
                    CheckWinConditions();
                }
                else
                    CheckButtons();
            }

            if (!SplitHandOver)
            {
                if (SplitHand.HasBlackjack() || SplitHand.IsBust() || (SplitHand.Count == 5 && (SplitHand.ActualValue < 21 || (SplitHand.HasAceEleven() && SplitHand.ActualValue <= 31))))
                {
                    SplitHandOver = true;
                    CheckWinConditions();
                }
                else
                    CheckButtons();
            }

            DisplayHands();
        }

        #region Button-Click Methods

        private void BtnConvertAce_Click(object sender, RoutedEventArgs e)
        {
            ConvertAce(MainHand);
            BindLabels();
        }

        private void BtnReturn_Click(object sender, RoutedEventArgs e) => ClosePage();

        private void BtnHit_Click(object sender, RoutedEventArgs e)
        {
            DealCard(MainHand);
            BtnSplit.IsEnabled = false;
            TxtInsurance.IsEnabled = false;
            BtnInsurance.IsEnabled = false;
            CheckWinConditions();
        }

        private void BtnDealHand_Click(object sender, RoutedEventArgs e)
        {
            MainBet = Int32Helper.Parse(TxtBet.Text);
            if (MainBet > 0 && MainBet <= GameState.CurrentHero.Gold)
                DealHand();
            else if (MainBet > GameState.CurrentHero.Gold)
                GameState.DisplayNotification("超过上限了，你不能赌更多的金子！", "Sulimn");
            else
                GameState.DisplayNotification("请输入有效的赌注", "Sulimn");
        }

        private void BtnStay_Click(object sender, RoutedEventArgs e)
        {
            MainHandOver = true;
            ToggleMainHandButtons(false);
            CheckWinConditions();
        }

        private void BtnSplit_Click(object sender, RoutedEventArgs e)
        {
            if (GameState.CurrentHero.Gold >= (MainBet * 2))
            {
                Functions.AddTextToTextBox(TxtBlackjack, "你的手裂开了.");
                SplitBet = MainBet;
                Card moveCard = new Card(MainHand.CardList[1]);
                MainHand.CardList.RemoveAt(1);
                SplitHand.AddCard(moveCard);
                BtnSplit.IsEnabled = false;
                PnlSplit.Visibility = Visibility.Visible;
                SplitHandOver = false;
                DealCard(MainHand);
                DealCard(SplitHand);
                CheckWinConditions();
            }
            else
                Functions.AddTextToTextBox(TxtBlackjack, "You cannot afford to double your wager to split your hands.");
        }

        private void BtnDoubleDown_Click(object sender, RoutedEventArgs e)
        {
            if (GameState.CurrentHero.Gold >= (MainBet * 2) + SplitBet + SidePot)
            {
                Functions.AddTextToTextBox(TxtBlackjack, "You double down on your main hand.");
                MainBet *= 2;
                DealCard(MainHand);
                MainHandOver = true;
                CheckWinConditions();
            }
            else
                Functions.AddTextToTextBox(TxtBlackjack, "You cannot afford to double down this hand.");
        }

        private void BtnInsurance_Click(object sender, RoutedEventArgs e)
        {
            int sidePot = Int32Helper.Parse(TxtInsurance.Text);

            if (sidePot <= MainBet / 2 && GameState.CurrentHero.Gold >= MainBet + SplitBet + sidePot)
            {
                SidePot = sidePot;
                ToggleInsurance(false);
            }
            else
                GameState.DisplayNotification("Your insurance bet must be less than or equal to half your main bet.", "Blackjack");
        }

        private void BtnConvertAceSplit_Click(object sender, RoutedEventArgs e) => ConvertAce(SplitHand);

        private void BtnDoubleDownSplit_Click(object sender, RoutedEventArgs e)
        {
            if (GameState.CurrentHero.Gold >= MainBet + (SplitBet * 2) + SidePot)
            {
                Functions.AddTextToTextBox(TxtBlackjack, "You double down on your split hand.");
                SplitBet *= 2;
                DealCard(SplitHand);
                SplitHandOver = true;
                ToggleSplitHandButtons(true);
                CheckWinConditions();
            }
            else
                Functions.AddTextToTextBox(TxtBlackjack, "You cannot afford to double down this hand.");
        }

        private void BtnStaySplit_Click(object sender, RoutedEventArgs e)
        {
            SplitHandOver = true;
            ToggleSplitHandButtons(true);
            CheckWinConditions();
        }

        private void BtnHitSplit_Click(object sender, RoutedEventArgs e)
        {
            DealCard(SplitHand);
            CheckWinConditions();
        }

        #endregion Button-Click Methods

        #region Page-Manipulation Methods

        /// <summary>Closes the Page.</summary>
        private void ClosePage()
        {
            if (_handOver)
            {
                GameState.SaveHero(GameState.CurrentHero);
                GameState.GoBack();
            }
        }

        public BlackjackPage()
        {
            InitializeComponent();
            CreateDeck(6);
            CardList.Shuffle();
            DisplayStatistics();
            TxtBlackjack.Text = "你走近一张正在玩21点的桌子。你坐下来。\n\n" +
            "\"想赌吗?\" 古董商问";
            TxtBet.Focus();
            BindLabels();
        }

        private void TxtBet_GotFocus(object sender, RoutedEventArgs e) => Functions.TextBoxGotFocus(sender);

        private void TxtBet_PreviewKeyDown(object sender, KeyEventArgs e) => Functions.PreviewKeyDown(e, KeyType.Integers);

        private void TxtBet_TextChanged(object sender, TextChangedEventArgs e)
        {
            Functions.TextBoxTextChanged(sender, KeyType.Integers);
            BtnDealHand.IsEnabled = TxtBet.Text.Length > 0;
        }

        private void TxtInsurance_TextChanged(object sender, TextChangedEventArgs e)
        {
            Functions.TextBoxTextChanged(sender, KeyType.Integers);
            BtnInsurance.IsEnabled = TxtInsurance.Text.Length > 0;
        }

        #endregion Page-Manipulation Methods
    }
}