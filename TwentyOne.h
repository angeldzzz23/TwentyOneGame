/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 12:43 AM
 * Specification for twentyOneGame Class
 */
 #ifndef TWENTYONE_H
 #define TWENTYONE_H

 // system level libraries
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 //User Libraries
 #include "Card.h"
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
  bool userDidSkipInstruction();
  void ClearScreen();
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
  bool userDoesNotWantToPlayAgain(); // finds out if the user wants to play again
  void nextPlayer(); //
  void initializeDeckOfCardsIntoArray(Card *arr, int s);
  void swap(Card *a, Card *b); // swaps two variables
  void shuffle(Card *arr, int size);
 };

#endif	/* TABLE_H */
