#include <string>
using namespace std;

List::List(){
  this->head = new ListNode;
}

List::~List(){
  this->clean();
}

void List::insert(string newer){
  ListNode *newnode = new ListNode;
  newnode->value = newer;

  if(this->head->next == NULL){
    this->head->next = newnode;
  }
  else{
    newnode->next = this->head->next;
    this->head->next = newnode;
  }
}

ListNode* List::getFirst(){
  return this->head->next;
}

ListNode* List::getNext(ListNode* current){
  return current->next;
}

bool List::atEnd(ListNode* current){
  if(current->next == NULL){
    return true;
  }
  else{
    return false;
  }
}
