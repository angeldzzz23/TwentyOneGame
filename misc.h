#include <iostream>

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
