#include <iostream>
#include "Suit.h"
using namespace std;


Suit1::Suit1() {
    // TODO
}

Suit1::Suit1(Suit _suit) {
  suit = _suit;
}

int Suit1::getTotalSuits() { return 4; }

string Suit1::getSuit() {
  switch(suit) {
    case 1:
      return "spades";
      break;
    case 2:
      return "hearts";
      break;
    case 3:
      return "clubs";
      break;
    case 4:
      return "diamonds";
      break;
    default:
      return "ppp Something went wrong";
      break;
  }
}


Suit* Suit1::getAllSuits() {
  Suit*all = new Suit[4];
  all[0] = Spades;
  all[1] = Hearts;
  all[2] = clubs;
  all[3] = diamond;
    return all;
}
