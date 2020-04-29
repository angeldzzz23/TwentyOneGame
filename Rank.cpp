/*
 * File:   Rank.h
 * Author: Angel Zambrano
 * Created on April 26, 2020
 */

#include "Rank.h"
#include <map>
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
      // dictionary to map int to numbers
     map<int, string> numbers;

     // create key value pairs
     numbers.insert(pair<int, string>(1, "A"));
     numbers.insert(pair<int, string>(11, "J"));
     numbers.insert(pair<int, string>(12, "Q"));
     numbers.insert(pair<int, string>(13, "K"));

  if (rank == 1) {
    return numbers[1];
  }
  else if (rank >= 1 && rank <= 10) {
    return to_string(rank);
  }
  else { // Face
    if (rank == 11) {
        return numbers[11];
      } else if (rank == 12) {
        return numbers[12];
      } else if (rank == 13) {
        return numbers[13];
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

  void helperFunctionForDisplayingRanks(int i) {  // function:

    if (i == 1) {
      cout << " "  << "A";
    } else if (i == 11) {
      cout << " " << "J";
    } else if (i == 12) {
      cout << " " << "Q";
    } else if (i ==  13) {
      cout << " " << "K";
    } else {
      cout << ' ' << i;
    }
  }

  void displayRanks() {
    // create a ranks list
    list<int> ranks;
     //push numbers into ranks
     for (int i=1; i<=13; ++i) ranks.push_back(i);
     for_each (ranks.begin(), ranks.end(), helperFunctionForDisplayingRanks);
  }
