/*
 * File:   Rank.h
 * Author: Angel Zambrano
 * Created on April 24, 2020, 10:41 PM
 */

#include "Rank.h"

// this is the total amount of ranks
//that can be in a card
int Rank::getAmountOfRanks() { return 13;}

Rank::Rank() {  } //

Rank::Rank(int n) {
  // Check if it is out o range
  if (n > getAmountOfRanks() || (n <= 0)) {
    rangeError();
  }
  // initialize rank
  setRank(n);
}

string Rank::getRank() {

  if (rank == 1) {
    return "A";
  }
  else if (rank >= 1 && rank <= 10) {
    return to_string(rank);
  }
  else { // Face
    if (rank == 11) {
        return "J";
      } else if (rank == 12) {
        return "Q";
      } else if (rank == 13) {
        return "K";
      }
  }
  return "YOU ARE WRONG!";
}

// exit if it is out of range
void Rank::rangeError() {
  cout << "ERROR: out of range " << endl;
  exit(EXIT_FAILURE);
}

// returns an rray of rank ints
int *Rank::getAllRanks() {
  int *arrayp = new int[13];

  for (int i  = 0; i < 13; i++) {
    arrayp[i] = i + 1;
  }
  return arrayp;
}


// returns the rank
int Rank::getRankAsInt() {

  return rank;
}
  // sets the rank
  void Rank::setRank(int n) {
    rank = n;
  }
