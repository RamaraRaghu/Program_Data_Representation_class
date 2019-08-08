//Rakshith Raghu, rr5de

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <algorithm>
#include "ListNode.h"
//#include "List.h"
#include <vector>
using namespace std;


class hashTable {
 private:
  vector<ListNode*> dictionary;
  unsigned int size;
 public:
  hashTable(int dic_size);
  void clean();
  int insert(string word);
  string get(int key);
  string remove(int key);
  //void rehash;   for the optimization section
  bool checkprime(unsigned int p);
  unsigned int  getNextPrime(unsigned int p);
  unsigned int  getTableSize();
  bool inDictionary(char*  word);
  bool find(ListNode* finder, string word);
  
};
#endif
