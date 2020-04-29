/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
 * Suit Class
 */

#ifndef SUIT_H
#define SUIT_H
#include <iostream>

enum Suit {Spades = 1, Hearts, clubs, diamond};
class Suit1 {
private:
  Suit suit;
public:
  Suit1(Suit);
  Suit1();
  std::string getSuit(); // get current suit
  int getTotalSuits(); // returns the int size
  Suit* getAllSuits(); // returns an array of all the types of suits
  void setSuit(Suit); // ses the suit

};
#endif
