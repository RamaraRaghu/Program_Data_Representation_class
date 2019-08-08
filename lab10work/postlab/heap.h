#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "huffnode.h"
using namespace std;

class heap {
 public:
  heap();
  heap(vector <int> vec, vector<char> vec_c);
  ~heap();
  void makeEmpty();
  bool isEmpty();
  void insert(huffnode *newone);
  huffnode* findMin();
  huffnode* deleteMin();
  int size();

  void consolidate();

  void generateCode(huffnode*tree, string code);
  map<char, string> getMap();
  
  
 private:
  map<char, string>  myMap;
  vector<huffnode*> hea;
  int heapsize;
  void percolateUp(int hole);
  void percolateDown(int hole);
  
  
};
#endif
