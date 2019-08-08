#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------  class definition
//---------------------------------------------------------- prototypes

int cmpMyObj(int *i, int& b);
/*void swapMyObj(float a, float b);*/

//--------------------------------------------------------------- main
int main () {
  int a = 0;
  int help[5] = {1,2,3,4,5};
  double b = 0;
  string flo = "help";
  string* fl = &flo;
  
  return 0;
}




//---------------------------------------------------------- cmpMyObj
int cmpMyObj(int* i, int &b) {
  return *i;
}
