/*
 * File:   Player.h
 * Author: Angel Zambrano
 * Created on April 26, 2020
 * PLayer header file
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <list>
#include <stack>

class Player {
private:
    string name; // name of player
    int deckSize; // total size of all deck added
    list <Card> deck; // deck
    static stack <string> playerNames; // stores all player names

public:
  list <Card>&getDeck(); // returns the address of deck
  void addCardToDeck(Card card); // adds card to deck
  void description(); // displays a descripcion of a card
  Player(); // default constructor
  Player(string); // constructor with name
  void setName(string); // sets name
  string getName(); // returns the name
  int getDeckSize(); // returns the total size of decks added
  void setDeckSize(int); // sets the size of the deck
  void clearDeck(); // clears deck
  void addPlayer(string); // add players into stack of players
  stack<string> getPlayerNames(); //
  void displayPlayerNames(); // displays all the player names
  void removePlayerFromStack();
};
#endif
