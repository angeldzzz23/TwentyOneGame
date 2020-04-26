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

};

#endif	/* RANK_H */
