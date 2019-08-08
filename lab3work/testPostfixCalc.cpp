//Rakshith Raghu, rr5de, 9/18/2018, testpostfixCalculator.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

int main () {
  postfixCalculator p;
  //working with only valid strings for the calculator
  string expression;
  bool flag = false;
  

  while(cin >> expression){
    cout << expression << endl;
    if(expression == "*"){
      p.multiply();
      flag = true;
    }
    if(expression == "/"){
      p.divide();
      flag = true;
    }
	//keeping these first so that if Order of Operations has to be implemented, I will have an easier time modifying code.
    if(expression == "-"){
      //checking for negative number is not necessary since the whole expression has to equal "-"
      p.subtract();
      flag = true;
    }
    if(expression == "+"){
      p.add();
      flag = true;
    }
    if(expression == "~"){
      p.negate();
      flag = true;
    }

//make sure only ints are passed
    if(flag == false){
      p.pushNum(atoi( expression.c_str() ));
      //cout << "this number was pushed into stack:" << p.topNum() << endl;
      //the line above is placed for debugging
    }
  flag = false;
  }

  //result here
  cout << "Result is: " << p.topNum() << endl;
  return 0;
}
