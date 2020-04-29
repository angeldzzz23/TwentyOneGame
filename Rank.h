/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 10:41 PM
 */

#ifndef RANK_H
#define RANK_H
#include <iostream>
#include <string>

using namespace std;

class Rank {
private:
  int rank;
  void rangeError(); // displays and extis with an error
public:
  Rank(int n); // constructor
  Rank(); // default contrustor
  int getAmountOfRanks(); //
  string getRank(); // retruns current rank
  int *getAllRanks(); // retruns an array of rank ints
  int getRankAsInt(); // returns the rank
  void setRank(int n);
  void printRanks();
};
#endif
