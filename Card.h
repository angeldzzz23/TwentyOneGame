/*
 * File:   Card.h
 * Author: Angel Zambrano
 * Created on April 23, 2020, 8:12 PM
 * Specification for the Table
 */


#ifndef Card_h
#define Card_h
#include "Rank.h"
#include "Suit.h"
#include <string>
using namespace std;

class Card  {
private:
  Suit1 suit;
  Rank rank;
public:
  Suit* getAllSuitTypes();
  void setCard(Suit1 _suit, Rank _rank); // sets the card with new suit and rank
  void setCard(Suit1 _suit); // sets card with new suit
  void setCard(Rank _rank); // sets card with new rank
  string* getAllRankTypes();
  void description();
  int getRankSize();
  Card(int rankType, Suit suitType); // Constructor
  Card();
};
#endif	/* TABLE_H */
