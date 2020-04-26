/*
 * File:   Table.h
 * Author: Dr. Mark E. Lehr
 * Created on January 22nd, 2020, 8:36 PM
 * Specification for the Table
 */

 #ifndef TWENTYONE_H
 #define TWENTYONE_H
 #include "Card.h"
 #include <iostream>
 #include "misc.h"

 class TwentyOne {
 private:
    int totalDeckOfCards;
    list <Card> deck;
    list <Card> playerOneDeck;
    list <Card> playerTwoDeck;
 public:
  void showCurrentDeck();
  void initialiGameState(); // sets card size to 52
  void getCardFromDeck(); // ask deal for one card
  void playTwoPlayerGame();
  int totalPlayerDeckSize(list <Card> player); // returns all cards added
  void currentUserDeck(list <Card> player); // prints the deck of the user
  Card dealCard(); // returns a card from deck
  void changeGameState();
  bool decision(list <Card> &player, int userInput);
  void playerAction(list <Card> &player);
  bool playerHasAnAce(list <Card> &player);
  bool userInputIsCorrect(int input);
  void winner(int playerOneSize, int playerTwoSize); // prints the winner of the game
  void displayHangmanInstructions();

 };

// initialize deck with 52 new cards
// intialize totalDeck
void TwentyOne::initialiGameState() {
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

  // push new cards into deck
  for (int s = 0; s < 4; s++) {
    for (int r = 0; r < 13; r++ ) {
      // add card into deck
      deck.push_back(Card(r+1, suits[s]));
      // increase size of deck
        size++;
    }
    cout << endl;
  }
  totalDeckOfCards = size;

  // initialize the two players with two cards

  // initializing player one with two cards
  playerOneDeck.push_back(dealCard());
  playerOneDeck.push_back(dealCard());

  // intialize player two with two cards
  playerTwoDeck.push_back(dealCard());
  playerTwoDeck.push_back(dealCard());

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
   // print out instructions
   cout << "Welcome to the two player game of 21" << endl << endl;

   int playerOneSize, playerTwoSize;

   cout << "playerOne: " << endl;
   playerAction(playerOneDeck);

   playerOneSize = totalPlayerDeckSize(playerOneDeck);
   cout << "Total cards is " << playerOneSize << endl << endl;

   // ask if player two is ready
   cout << "player 2 are you ready" << endl;
  // clear screan

  cout << "PlayerTwo" << endl;
  playerAction(playerTwoDeck);
  playerTwoSize = totalPlayerDeckSize(playerTwoDeck);

   // Check who won
   winner(playerOneSize,playerTwoSize);



   // ask if they would like to play again.

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
int TwentyOne::totalPlayerDeckSize(list <Card> player) {
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
    cout << "Your current Deck is: " << endl;
    currentUserDeck(player);
    cout << endl;


    // Ask user what they would like to do
    cout << "would you like to stand or would you like to hit" << endl;
    cout << "press 1 to hit dealer" << endl;
    cout << "press 2 if you are satisfied with your dealing" << endl;
    cin >>userInput;
    // call decision function
    playerIsNotDone = decision(player,userInput);

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

// prints the winner of the game
// 0 is a tie
// 1 player 1 win
// 2 player 2 win
void TwentyOne::winner(int playerOneSize, int playerTwoSize) {

  int p1size, p2size;

cout << playerOneSize << endl;
cout << playerTwoSize << endl;

  // player one is 21
  if (playerOneSize == 21 && playerTwoSize != 21) {
    cout << "player 1 won" << endl;
  }
    // player two is 21
  if (playerTwoSize == 21 && playerOneSize != 21) {
    cout << "player 2 won" << endl;
  }

  // tie
  if (playerTwoSize == 21 && playerOneSize == 21) {
    cout << "Both players tied" << endl;
  }

  // if both are not less than 21
  if (playerOneSize < 21 && playerTwoSize < 21) {
    //
    if (playerOneSize > playerTwoSize) {
      cout << "player 1 won!" << endl;
    }
    //
    if (playerOneSize == playerTwoSize) {
      cout << "it is a tie!" << endl;
    }
    //
    if (playerOneSize < playerTwoSize) {
      cout << "player 2 won!" << endl;
    }

  }

  if (playerOneSize > 21 && playerTwoSize > 21) {
    // might want to refactor this
    if (playerOneSize < playerTwoSize) {
      cout << "player 1 won!" << endl;
    } else if (playerOneSize == playerTwoSize) {
      cout << "it is a tie!" << endl;
    } else if (playerTwoSize < playerOneSize) {
      cout << "player 2 won!" << endl;
    }
  }
}

 #endif	/* TABLE_H */

void TwentyOne::displayHangmanInstructions() {

      ClearScreen();
      cout << setw(45) << "WELCOME TO 21 Game" << endl;
      cout << endl;
      cout << "Press [enter] to read instructions or press any other key to skip" << endl;

      if (userDidSkipInstruction()) {
          ClearScreen();
        cout << setw(30) <<"How to Play" << endl;
        cout << endl;
        cout << "* In each game you will be given 2 cards to start" << endl;
        cout << "* You have the option to stand or hit the dealer."<< endl;
        cout <<endl;
        cout << "Press [enter] to reads more or any other key to skip" << endl;

        if (userDidSkipInstruction()) {
          ClearScreen();
          cout << setw(30)<<"SCORING & Tips"<< endl;
          cout << endl;
          cout << "* Which ever player reaches 21 wins" << endl;
          cout << "* Remember An ace can be either 1 or 11" << endl;
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
