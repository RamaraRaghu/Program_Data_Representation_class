//Rakshith Raghu, rr5de, 9/15/2018, postfixCalculator.cpp
#include "postfixCalculator.h"
using namespace std;

//class declarations go here
postfixCalculator::postfixCalculator(){
  this->numbers = new stack;
}

postfixCalculator::~postfixCalculator(){
  delete this->numbers;
}


//the stack functions go here
bool postfixCalculator::emptyNum(){
  return this->numbers->empty();
}

void postfixCalculator::pushNum(int e){
  this->numbers->push(e);
}

void postfixCalculator::popNum(){
  if(this->emptyNum() == false){
    this->numbers->pop();
  }
}

int postfixCalculator::topNum(){
  if(this->emptyNum() == false){
    return this->numbers->top();
  }
  return 0;
}


//operation functions go here
void postfixCalculator::add(){
  if(this->numbers->size()  >= 2){
    int x = this->topNum();
    this->popNum();
    int y = this->topNum();
    this->popNum();
    this->pushNum(x + y);
  }
}

void postfixCalculator::subtract(){
  if(this->numbers->size() >= 2){
    int x = this->topNum();
    this->popNum();
    int y = this->topNum();
    this->topNum();
    this->pushNum(y-x);
  }
}

void postfixCalculator::multiply(){
  if(this->numbers->size() >= 2){
    int x = this->topNum();
    this->popNum();
    int y = this->topNum();
    this->popNum();
    this->pushNum(x * y);
  }
}

void postfixCalculator::divide(){
  if(this->numbers->size() >= 2){
    int x = this->topNum();
    this->popNum();
    int y = this->topNum();
    this->popNum();
    this->pushNum(y/x);
  }
}

void postfixCalculator::negate(){
  if(this->numbers->size() >= 1){
    int y = this->topNum();
    this->popNum();
    this->pushNum(-1*y);
  }
}






