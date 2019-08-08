//Rakshith Raghu, rr5de
#include <iostream>
using namespace std;

int xton (int a, int b) {

  if(b == 0){
    return 1;
  }
  if(b > 0){
    return a*xton(a, b-1);
  }

  return 0;  //makes sure it returns something if it gets to this stage
}

int main() {
  int x, y, z;
  cin >> x;
  cin >> y;
  z = xton(x,y);
  cout << x << " ^  " << y << " = " << z << endl;
  return 0;
}

