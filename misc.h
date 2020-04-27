/*
 * File:   TwentyOne.h
 * Author: Angel Zambrano
 * Created on April 26, 2020, 8:36 PM
 * Specification for the Table
 */


#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <ctype.h>

using namespace std;
bool userDidSkipInstruction();

  // http://www.cplusplus.com/forum/articles/10515/
  void ClearScreen() {
      cout << string( 100, '\n' );
    }

    // Checks if user entered "\n"
  bool userDidSkipInstruction() {
    string str;
    getline(cin, str);

    if (str.length() == 0) {
        cout << endl << endl << endl;
        return true;
    }
   return false;

  }
