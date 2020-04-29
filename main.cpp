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

  // initialize A game of twentyOne
  TwentyOne n(names.front(), names.back());

 // vector<int> myvector;
 // myvector.push_back(10);
 // myvector.push_back(20);
 // myvector.push_back(30);

 // list<string> namesss;
 // namesss.push_back("angel");
 // namesss.push_back("angel");
 // namesss.push_back("angel");


 // std::cout << "myvector contains:";
 //  for_each (myvector.begin(), myvector.end(), myfunction);
 //  std::cout << '\n';
 //
 //
 //  cout << "my link list contains" << endl;
 //  for_each(namesss.begin(), namesss.end(), myfunction2);
 //
 //   list<int> ranks;
 //
 //   for (int i=1; i<=13; ++i) ranks.push_back(i);
 //   for_each(ranks.begin(), ranks.end(), myfunction);







  // start tutorial
  // n.displayInstructions();
  // setting up initial game state
  n.initialiGameState();
  // starting game
  // n.playTwoPlayerGame();

  return 0;
}
//Function Implementations
