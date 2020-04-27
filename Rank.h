#ifndef RANK_H
#define RANK_H
#include <iostream>
#include <string>

using namespace std;

class Rank {
private:
  int rank;
public:
  Rank(int n); // constructor
  Rank();
  int getAmountOfRanks();
  string getRank();
  int *getAllRanks();
  void rangeError();
  int getRankAsInt(); // returns the rank
};
#endif	/* RANK_H */
