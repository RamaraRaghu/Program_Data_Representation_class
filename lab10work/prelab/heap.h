#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "treenode.h"
using namespace std;

class heap {
 public:
  heap();
  heap(vector <int> vec, vector<char> vec_c);
  ~heap();
  void makeEmpty();
  bool isEmpty();
  void insert(treenode *newone);
  treenode* findMin();
  treenode* deleteMin();
  int size();
  int getCost();

  void consolidate();

  void generateCode(treenode*tree, string code);
  map<char, string> getMap();
  
  
 private:
  map<char, string>  myMap;
  vector<treenode*> hea;
  int heapsize;
  void percolateUp(int hole);
  void percolateDown(int hole);

  int cost;
  
  
};
#endif
