/*
 * File:   Main.cpp
 * Author: Angel Zambrano
 * Created on April 23, 2020
 * Purpose: start of the program
 */

// system level libraries
#include <iostream>
#include <list>
#include <iterator>
#include <queue>
#include <set>
#include <map>
using namespace std;  //Library Scope

//User Libraries
#include "TwentyOne.h"
#include "Card.h"

//Execution Starts Here
int main(void) {
  // creating a Queue to store names
  queue <string> names;
  names.push("Angel");
  names.push("David");
  // initialize a game of twentyOne
  TwentyOne n(names.front(), names.back());
  // start tutorial
  n.displayInstructions();
  // setting up initial game state
  n.initialGameState();
  // starting game
  n.playTwoPlayerGame();
// program ends
  return 0;
}
//Function Implementations
