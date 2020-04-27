/*
 * File:   Player.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
 * PLayer header file
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <list>

class Player {
private:
    string name; // name of player
    int deckSize; // total size of all deck added
    list <Card> deck; // deck
public:
  list <Card>&getDeck(); // returns the address of deck
  void addCardToDeck(Card card); // adds card to deck
  void description(); // displays a descripcion of a card
  void getPlayerNames(string name); //displays player name
  Player(); // default constructor
  Player(string); // constructor with name
  void setName(string); // sets name
  string getName(); // returns the name
  int getDeckSize(); // returns the total size of decks added
  void setDeckSize(int); // sets the size of the deck
  void clearDeck(); // clears deck
};
#endif
