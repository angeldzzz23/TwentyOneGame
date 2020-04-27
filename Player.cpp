/*
 * File:   Player.cpp
 * Author: Angel Zambrano
 * Created on April 26, 2020, 7:30 PM
 * cpp file
 */

 #include "Player.h"


 // default constructor
 Player::Player() {
   setName("Default Name");
 }
 // clears deck
 void Player::clearDeck() {
   deck.clear();
 }
 // returns deck size
 int Player::getDeckSize() {
   return deckSize;
 }
 // sets deckSize
 void Player::setDeckSize(int _deckSize) {
   deckSize = _deckSize;
 }

 // returns the name
 string Player::getName() {
   return name;
 }
 // sets the name
 void Player::setName(string _name) {
   name = _name;
 }
 // default constructor
 Player::Player(string _name) {
   name = _name;
 }
 // returns the adress of deck
 list <Card> &Player:: getDeck() {
   return deck;
 }

 // pushs deck to card
 void Player::addCardToDeck(Card card) {
   deck.push_back(card);
 }


 void Player::description() {
   cout << getName()<< ": " << endl;
   // card iterator
   list <Card> :: iterator it;
   // prints out every element in the deck
   for(it = deck.begin(); it != deck.end(); ++it)  {
     it->description();
   }
   cout << '\n';
   cout << "Size of deck added: " << getDeckSize() << endl;
 }
