#include <iostream>
#include <list>
#include <iterator>
#include "TwentyOne.h"

using namespace std;

int main(void) {

  TwentyOne n("Angel", "David");
  n.initialiGameState();
  n.playTwoPlayerGame();

  return 0;
}
