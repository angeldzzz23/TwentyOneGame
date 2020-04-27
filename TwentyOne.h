/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
 * Specification for twentyOneGame Class
 */

 #ifndef TWENTYONE_H
 #define TWENTYONE_H
 #include "Card.h"
 #include "Player.h"
 #include <iostream>
 #include "misc.h"
 #include "Player.h"
 #include "stdlib.h"

 class TwentyOne {
 private:
    int totalDeckOfCards;
    list <Card> deck;
    Player playerJuan;
    Player playerDos;
 public:
  TwentyOne(); // default constructor
  TwentyOne(string, string); //
  void showCurrentDeck();
  void initialiGameState(); // sets card size to 52
  void playTwoPlayerGame(); // starts a game
  int getTotalPlayerDeckSize(list <Card> player); // gets the size of decks added of a player
  void currentUserDeck(list <Card> player); // prints the deck of the user
  Card dealCard(); // returns a card from deck
  bool decision(list <Card> &player, int userInput);
  void playerAction(list <Card> &player);
  bool playerHasAnAce(list <Card> &player); // finds out if there is an ace on the use's deck
  bool userInputIsCorrect(int input);
  void winner(Player playerOne, Player playerTwo); // prints the winner of the game
  void displayInstructions();
  bool userDoesNotWantToPlayAgain();
  void nextPlayer();
  void printCurrentDeck();
  void initializeDeckOfCardsIntoArray(Card *arr, int s);
  void swap(Card *a, Card *b);
  void shuffle(Card *arr, int size);

 };

TwentyOne::TwentyOne() { // constructor

}

TwentyOne::TwentyOne(string playerOneName, string playerTwo)
:playerJuan(playerOneName), playerDos(playerTwo)
{

}

// initialize deck with 52 new cards
// intialize totalDeck
void TwentyOne::initialiGameState() {

  Card cardArray[55]; // s

  // clear deck if you are playig again
  if (!(deck.empty() && playerJuan.getDeck().empty() && playerDos.getDeck().empty())) {
    // clear everything. Reset numbers
    deck.clear();
    playerJuan.clearDeck();
    playerJuan.setDeckSize(0);

    playerDos.clearDeck();
    playerDos.setDeckSize(0);

    totalDeckOfCards = 0;
  }

  initializeDeckOfCardsIntoArray(cardArray, 52);

    // shuffle
    shuffle(cardArray, 52);
    // initialize Deck with shuffled Cards
    for(int i = 0; i < 52; i++) {
      deck.push_back(cardArray[i]);
    }

    cout << deck.size() << endl;

  // initiaize each player with one card

  // initializing player one with two cards
  playerJuan.addCardToDeck(dealCard());
  playerJuan.addCardToDeck(dealCard());

  // intialize player two with two cards

  // using class
  playerDos.addCardToDeck(dealCard());
  playerDos.addCardToDeck(dealCard());
}

 // prints out deck using the iterator
 void TwentyOne::showCurrentDeck() {
   list <Card> :: iterator it;
   for(it = deck.begin(); it != deck.end(); ++it)  {
     it->description();
   }
   cout << '\n';
  cout << totalDeckOfCards << endl;
 }

 void TwentyOne::playTwoPlayerGame() {
   // clear screen
   ClearScreen();

   cout << endl;

   cout << playerJuan.getName()<< ": " << endl;
   playerAction(playerJuan.getDeck());

   playerJuan.setDeckSize(getTotalPlayerDeckSize( playerJuan.getDeck()));

   cout << "Total cards is " << playerJuan.getDeckSize() << endl << endl;

   // ask if player two is ready
    nextPlayer();
    // clear screen
    ClearScreen();
    // show dealers deck

    // show previous player's deck
    cout << "Last player "<<playerJuan.getName()<< ": " << endl;
    currentUserDeck(playerJuan.getDeck());
    cout << endl;


    cout <<playerDos.getName() << "(Current Player)"<< ": " << endl;
    playerAction(playerDos.getDeck());
    playerDos.setDeckSize(getTotalPlayerDeckSize( playerDos.getDeck()));

    ClearScreen();

    cout << playerJuan.getName() << " total size is " <<  playerJuan.getDeckSize() << endl;
    cout << playerDos.getName()<< " total size is " <<  playerDos.getDeckSize() << endl;

  // Check who won
   winner(playerJuan,playerDos);

   cout << endl;
   // ask player if they want to play again
   if (!userDoesNotWantToPlayAgain()) {
     // reset cards in initial game state
     initialiGameState();
     // call playTwoPlayerGame
     playTwoPlayerGame();
   }
 }

void TwentyOne::currentUserDeck(list <Card> player) {
  list <Card> :: iterator it;
  for(it = player.begin(); it != player.end(); ++it)  {
    it->description();
  }
}

Card TwentyOne:: dealCard() {
  // get the first card from the deck
  Card card = deck.front();
  // remove first card from deck
  deck.pop_front();
  // decrease size of deck
  totalDeckOfCards--;
  // return the first card from the deck
  return card;
}

// takes care of special cases
int TwentyOne::getTotalPlayerDeckSize(list <Card> player) {
  int userInput; // input can only be
  bool inputIsNotCorrect = true;

  if (playerHasAnAce(player)) {

    do {
      cout << "Would you like your ace to be 1 or 21" << endl;
      cout << "press 1 for 1"  << endl;
      cout << "press 2 for 11" << endl;
      cin >> userInput;

      inputIsNotCorrect = !userInputIsCorrect(userInput);

    }while(inputIsNotCorrect);

  }

  int size = 0;

  list <Card> :: iterator it;
  for(it = player.begin(); it != player.end(); ++it)  {
    if (it->getRankSize() == 1 && userInput == 2) {
      size += 11;
      continue;
    } else if (it->getRankSize() >= 11 && it->getRankSize() <= 13) {
      size += 10;
      continue;
    }
      size += it->getRankSize();
  }
  return size;
}

bool TwentyOne::decision(list <Card> &player, int userInput) {

  // if userInput is 1. Add a card into its deck
  if (userInput == 1) {
    // add card into player deck
    player.push_back(dealCard());


  }   // if userInput is 2. Then do nothing.
  else if (userInput == 2) {
    return false;
  }
return true;
}

void TwentyOne::playerAction(list <Card> &player) {
  bool playerIsNotDone =  true;
  int userInput;
  do {
    // print the cards user has
    cout << "Current Deck is: " << endl;
    currentUserDeck(player);
    cout << endl;

    // Ask user what they would like to do
    cout << "would you like to stand or would you like to hit" << endl;
    cout << "press 1 to hit dealer" << endl;
    cout << "press 2 if you are satisfied with your dealing" << endl;
    cin >>userInput;
    // call decision function
    playerIsNotDone = decision(player,userInput);
    ClearScreen();

  } while(playerIsNotDone);

}

bool TwentyOne::playerHasAnAce(list <Card> &player) {
    int cardRank;
    list <Card> :: iterator it;
    for(it = player.begin(); it != player.end(); ++it) {
      if (it->getRankSize() == 1) {
        return true;
      }
    }
    return false;
  }

bool TwentyOne::userInputIsCorrect(int input) {
  if (input <= 2 && input > 0) {
      return true;
  }
  return false;
}


bool TwentyOne::userDoesNotWantToPlayAgain() {
bool incorrectInput = true;
int userInput;
  do {
    cout << "Would you like to play again?" << endl;
    cout << "Enter 1 to quit" << endl;
    cout << "Enter 2 to play again" << endl;
    cin>>userInput;

  }while(!(userInput <= 2 && userInput >= 1));

return (userInput ==  1) ? false : false;
}

// prints the winner of the game
// 0 is a tie
// 1 player 1 win
// 2 player 2 win
void TwentyOne::winner(Player playerOne, Player playerTwo) {
  int p1size, p2size;
  int playerOneSize = playerOne.getDeckSize();
  int playerTwoSize = playerTwo.getDeckSize();

  // player one is 21
  if (playerOneSize == 21 && playerTwoSize != 21) {
    cout << "player 1 won" << endl;
    cout << playerOne.getName() << " won!";
  }
    // player two is 21
  if (playerTwoSize == 21 && playerOneSize != 21) {
    cout << playerTwo.getName() << " won!";

  }

  // tie
  if (playerTwoSize == 21 && playerOneSize == 21) {
    cout << "Both players tied" << endl;
  }

  // if both are not less than 21
  if (playerOneSize < 21 && playerTwoSize < 21) {
    //
    if (playerOneSize > playerTwoSize) {
        cout << playerOne.getName() << " won!";
    }
    //
    if (playerOneSize == playerTwoSize) {
      cout << "it is a tie!" << endl;
    }
    //
    if (playerOneSize < playerTwoSize) {
      cout << playerTwo.getName() << " won!";
    }
  }

  if (playerOneSize > 21 && playerTwoSize > 21) {
    // might want to refactor this
    if (playerOneSize < playerTwoSize) {
      cout << playerOne.getName() << " won!";
    } else if (playerOneSize == playerTwoSize) {
      cout << "it is a tie!" << endl;
    } else if (playerTwoSize < playerOneSize) {
        cout << playerTwo.getName() << " won!";
    }
  }
}

void TwentyOne::displayInstructions() {

      ClearScreen();
      cout << setw(45) << "WELCOME TO 21 GAME" << endl;
      cout << endl;
      cout << "Press [enter] to read instructions or press any other key to skip" << endl;

      if (userDidSkipInstruction()) {
          ClearScreen();
        cout << setw(30) <<"How to Play" << endl;
        cout << endl;
        cout << "* This is a two player game" << endl;
        cout << "* In each game you will be given 2 cards to start with" << endl;
        cout << "* You have the option to stand or hit the dealer"<< endl;
        cout <<endl;
        cout << "Press [enter] to reads more or any other key to skip" << endl;

        if (userDidSkipInstruction()) {
          ClearScreen();
          cout << setw(30)<<"SCORING & Tips"<< endl;
          cout << endl;
          cout << "* Which ever player reaches 21 wins" << endl;
          cout << "* Remember an ace can be either 1 or 11" << endl;
          cout << "* J Q and K are all counted as ten" << endl;
          cout <<endl;
          cout << "[Press any key to start a new game]"<< endl;

          if (userDidSkipInstruction()) {
              ClearScreen();
            return;
          } else {
              ClearScreen();
            return;
          }

        } else {
          ClearScreen();
          return;
        }
      } else {
        ClearScreen();
        return;
      }
}

void TwentyOne::nextPlayer() {
  string k;
  cout << playerDos.getName() << " Press any other key to continue" << endl;
  cin >> k;
}

void TwentyOne::initializeDeckOfCardsIntoArray(Card *arr, int s) {
  // TODO

  Rank rank;
  Suit1 suit;

  int *ranks; // array of ints
  Suit *suits; // array of suit types

  // getting array of all ranks
  ranks = rank.getAllRanks();
  // getting array of all suit types
  suits = suit.getAllSuits();

  // deck size
  int size = 0;

  // initialize deck into array

  // push new cards into deck
  for (int s = 0; s < 4; s++) {
    for (int r = 0; r < 13; r++ ) {
      // add card into deck
      // deck.push_back(Card(r+1, suits[s]));
      arr[size] = Card(r+1, suits[s]);
      // increase size of deck
        size++;
    }
    cout << endl;
  }

  totalDeckOfCards = size;

}

void TwentyOne::swap(Card *a, Card *b) {
  Card temp = *a;
  *a = *b;
  *b = temp;
}

// Shuffles the array
void TwentyOne::shuffle(Card *arr, int size) {
  srand (time(NULL));
  for (int i = size - 1; i > 0; i--)
  {
      int j = rand() % (i + 1);
      swap(&arr[i], &arr[j]);
  }
}



#endif	/* TABLE_H */
