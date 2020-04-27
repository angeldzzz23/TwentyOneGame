/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
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
  string* getAllRankTypes();
  void description();
  int getRankSize();
  Card(int rankType, Suit suitType); // Constructor
  Card();
};
#endif	/* TABLE_H */
