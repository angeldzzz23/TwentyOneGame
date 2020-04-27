/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
 * Specification for the Table
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
class Player {
private:
    string name;
    int deckSize;
    list <Card> deck;
public:
  void addToDeck();
  list <Card>&getDeck();
  void addCardToDeck(Card card);
  void description();
  void getPlayerNames(string name);
  Player();
  Player(string);
  void setName(string);
  string getName();
  int getDeckSize();
  void setDeckSize(int);
  void clearDeck();

};

Player::Player() {
  setName("Default Name");
}
void Player::clearDeck() {
  deck.clear();
}

int Player::getDeckSize() {
  return deckSize;
}

void Player::setDeckSize(int _deckSize) {
deckSize = _deckSize;
}

string Player::getName() {
  return name;
}

void Player::setName(string _name) {
  name = _name;
}

Player::Player(string _name) {
  name = _name;
}

list <Card> &Player:: getDeck() {
  return deck;
}

void Player::addCardToDeck(Card card) {
  deck.push_back(card);
}

void Player::description() {
  cout << "Player 1" << endl;
}
#endif
