/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020
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
    list <Card> deck;
    Player playerJuan;
    Player playerDos;
    static void helperFunction(Card);
    bool userDidSkipInstruction();
    void ClearScreen();
    void displayCurrentDeck(); // prints out the current deck
    int getTotalPlayerDeckSize(list <Card> player); // gets the size of decks added of a player
    void displayTheDeckOf(list <Card> player); // prints the deck of the user
    Card dealCard(); // returns a card from deck
    bool makeDecision(list <Card> &player, int userInput); //
    void playerAction(list <Card> &player);
    bool anAceIsFoundInPlayer(list <Card> &cards); // finds out if there is an ace on the use's deck
    bool userInputIsCorrect(int input);
    void declareWinner(Player playerOne, Player playerTwo); // prints the winner of the game
    bool userDoesNotWantToPlayAgain(); // finds out if the user wants to play again
    void pauseGame(); //
    void initializeDeckOfCardsIntoArray(Card *arr, int s);
    void swap(Card *a, Card *b); // swaps two variables
    void shuffle(Card *arr, int size);
 public:
  TwentyOne(); // default constructor
  TwentyOne(string, string); //
  void initialGameState(); // sets card size to 52
  void playTwoPlayerGame(); // starts a game
  void displayInstructions();
 };
#endif
