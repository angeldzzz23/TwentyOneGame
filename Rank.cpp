#include "Rank.h"

int Rank::getAmountOfRanks() { return 13;}

Rank::Rank() {  } //  TO DO

Rank::Rank(int n) {
  // Check if it is out o range
  if (n > getAmountOfRanks() || (n <= 0)) {
    rangeError();
  }
  // initialize rank
  rank = n;
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

void Rank::rangeError() {
  cout << "ERROR: out of range " << endl;
  exit(EXIT_FAILURE);
}

int  *Rank::getAllRanks() {
  int *arrayp = new int[13];

  for (int i  = 0; i < 13; i++) {
    arrayp[i] = i + 1;
  }

  return arrayp;
}
