/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
 * Specification for the Table
 */


#include "Card.h"


Card::Card() {
  // DO Nothing
}

Card::Card(int rankType, Suit suitType)
: rank(rankType), suit(suitType)
{
  // TODO
}

string* Card::getAllRankTypes() {
  string *ranks = new string[13];
  for (int i = 1; i <= 13; i++) {
    ranks[i - 1] = to_string(i);
  }
  return ranks;
}

void Card::description() {
  cout << "Card: " << "Of Type " << suit.getSuit() << " and Rank: " << rank.getRank() << endl;
}

Suit* Card::getAllSuitTypes() {

Suit*all = new Suit[4];
all[0] = Spades;
all[1] = Hearts;
all[2] = clubs;
all[3] = diamond;
  return all;
}

int Card::getRankSize() {
  return rank.getRankAsInt();
}
