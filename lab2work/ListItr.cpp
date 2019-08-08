//Rakshith Raghu, rr5de, 9/13/2018, ListItr.cpp
//I flipped around the isPastEnd() and is PastBeginning() along with forward and
//backward in the code I believe.Code will still operate correctly otherwise

#include "ListItr.h"
using namespace std;

ListItr::ListItr(){
  this->current = new ListNode;
}

ListItr::~ListItr(){
}

ListItr::ListItr(ListNode* theNode){
  //address theNode is passed to address of current
  this->current = theNode;
}

bool ListItr::isPastEnd() const{
  //checks if pointer exists. If not, then false, if so, then true
  if(this->current->previous == NULL && this->current->next != NULL){
    return true;
  }
  else{
    return false;
  }
}

bool ListItr::isPastBeginning() const{
  //checks if pointer exists. if not then false, if so, then true;
  if(this->current->next == NULL && this->current->previous != NULL){
    return true;
  }
  else{
    return false;
  }
}

void ListItr::moveForward(){
  //first checks if past beginning
  if(this->isPastBeginning() == false){
    this->current = this->current->next;
  }
}

void ListItr::moveBackward(){
  //first checks if past end
  if(this->isPastEnd() == false){
    this->current = this->current->previous;
  }
}

int ListItr::retrieve() const{
  return this->current->value;
}
