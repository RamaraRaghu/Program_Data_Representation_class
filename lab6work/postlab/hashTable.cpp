#include "hashTable.h"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

hashTable::hashTable(int dic_size){
  unsigned int dict_size = (unsigned int) dic_size;
  if(checkprime(dict_size) == false){
    dic_size = getNextPrime(dict_size);
  }
  size = dict_size;
  for(int i = 0; i < size; i++){
    dictionary.push_back(NULL);
  }
}

void hashTable::clean(){
  this->dictionary.clear();
}

int hashTable::insert(string word){
  int index = 0;

  //index will be the total size of the word(and the word will only be inserted if longer than 3)
  if(word.length() >= 3){
    //for loop adds to index
    for(int i = 0; i < word.length(); i++){
      index = ((int) word[i]) + index;
    }

    //get the key for the word
    index = index % this->size;

    //now check if the index is filled or not
    if(this->dictionary[index] == NULL){
      ListNode *input = new ListNode;
      input->value = word;
      this->dictionary[index] = input;
    }
    else{
      this->dictionary[index]->addNode(word);
    }
    return index;
  }
  else{
    return 0;
  }
}

// void hashTable::rehash()
//bool hashTable::checkprime(int p)
//int hashTable::getNextPrime(int p)
//The hashtable size, for right now, will be decided on by a pass of the list

string hashTable::get(int key){
  return dictionary[key]->value;
}

unsigned int hashTable::getTableSize(){
  return this->size;
}


//basically check through the listnodes
bool hashTable::inDictionary(char* word){
  string check(word);
  int index = 0;

  for(int i = 0; i < check.length(); i++){
    index = ((int) check[i]) + index;
  }

  if(this->dictionary[index] == NULL){
    return false;
  }
  else{
    return find(this->dictionary[index], check);
  }

  return false;
}

bool hashTable::find(ListNode* finder, string word){
  if(finder == NULL){
    return false;
  }
  
  if(finder->value == word){
    return true;
  }

  return find(finder->next, word);
}

bool hashTable::checkprime(unsigned int p){
  if(p <= 1)
    return false;
  if(p == 2)
    return true;
  if(p % 2 == 0)
    return false;
  for(int i = 3; i*i <= p; i += 2)
    if(p % i == 0)
      return false;
  return true;
}

unsigned int hashTable::getNextPrime(unsigned int p){
  while(checkprime(p) == false){
    p = p + 1;
  }
  return p;
}
