#include <iostream>
#include <cstdlib>
using namespace std;

extern "C" int product(int x, int y);
extern "C" int power(int x, int y);

int main(){
  int x = 0;
  int y = 0;

  cout << "Please enter an integer number x:";
  cin >> x;
  cout << "Please enter an integer number y:";
  cin >> y;

  int output1 = product(x,y);
  int output2 = power(x,y);

  cout << "The product is: " << output1 << endl;
  cout << "The power is: " << output2 << endl;
  return 0;
}
