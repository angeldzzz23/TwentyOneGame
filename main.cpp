#include <iostream>
#include "Card.h"
#include "Rank.h"
#include <list>
#include <iterator>
#include "TwentyOne.h"


using namespace std;
int main(void) {
  
  TwentyOne n;
  n.initialiGameState();
  n.playTwoPlayerGame();

  return 0;
}
