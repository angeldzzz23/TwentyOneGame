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
   addPlayer("Default Name");
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
   setName(name);
   addPlayer(name);
 }
 // returns the adress of deck
 list <Card> &Player:: getDeck() {
   return deck;
 }

 // pushs deck to card
 void Player::addCardToDeck(Card card) {
   deck.push_back(card);
 }

 // displays a descripcion of the player
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

 stack <string> Player::playerNames;

 // appends player into stack of players
 void Player::addPlayer(string _name) {
   // adds player to the top of the stack of player names
   playerNames.push(_name);
 }

 // return playerNames
 stack<string> Player::getPlayerNames() {
   return playerNames;
 }

void Player::removePlayerFromStack() {
  playerNames.pop();
 }

 // displays the players in a game
 void  Player::print() {
   stack <string> s =  playerNames;

   while (!s.empty())
   {
       cout << " " << s.top();
       s.pop();
   }
   cout << '\n';

 }
