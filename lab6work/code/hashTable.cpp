#include "hashTable.h"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

hashTable::hashTable(int dic_size){
  int size = dic_size;
  for(int i = 0; i < size; i++){
    dictionary.push_back("a");
  }
}

int hashTable::insert(string word){
  //using size of first three letters for the key
  if(word.length() >= 3){
    
    int index = 0;
    for(int i = 0; i < 2; i++){
      index = ((int) word[i]) + index;
    }

  //get the key here
    index = index % this->size;

  //insert into dictionary
    if(dictionary[index] == "a"){
      dictionary[index] = word;
    }
  else{
    //idea here is to use linear collision(which is inefficient and will be
    //replaced with linknode buckets for the optimization stage
    int i = index;
    while(i < this->size){
      if(dictionary[index] == "a"){
	dictionary[index] = word;
	i = size + 1;
      }
      else{
	index = index + 1;
	i = i + 1;
	if(i == this->size - 1){
	  i = 0;
	  index = 0;
	}
      }
     
    }
  }

  return index;
  }
  else{
    return 0; //if the string is less than 3 size dont even put it into the list
  }
}

// void hashTable::rehash()
//bool hashTable::checkprime(int p)
//int hashTable::getNextPrime(int p)
//The hashtable size, for right now, will be decided on by a pass of the list

string hashTable::find(int key){
  return dictionary[key];
}

int hashTable::getTableSize(){
  return this->size;
}

bool hashTable::inDictionary(char* word){
  string check(word);

  if(std::find(dictionary.begin(), dictionary.end(), check) != dictionary.end()){
    return true;
  }
  else{
    return false;
  }
}
