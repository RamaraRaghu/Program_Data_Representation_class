#include "heap.h"
#include <iostream>
using namespace std;

heap::heap(){
  heapsize = 0;
  huffnode *null_head = new huffnode;
  hea.push_back(null_head);
}

heap::heap(vector<int> vec, vector<char> vec_c){
  this->heapsize = vec.size();
  

  for(int i = 0; i < vec.size(); i++){
    huffnode *newone = new huffnode(vec_c[i],vec[i]);
    hea.push_back(newone);
  }
  hea.push_back(hea[0]);

  huffnode *null_head = new huffnode;

  hea[0] = null_head;

  for(int i = heapsize/2; i > 0; i--){
    percolateDown(i);
  }
}

heap::~heap(){
}

void heap::insert(huffnode* newone){
  huffnode* newnode = new huffnode(newone->getChar(), newone->getFreq());
  newnode->left = newone->left;
  newnode->right = newone->right;
  
  hea.push_back(newnode);

  percolateUp(++heapsize);
}

void heap::percolateUp(int hole){
  huffnode *placeholder = hea[hole];
  int x = placeholder->getFreq();

  while(hole > 1 && x < hea[hole/2]->getFreq()){
    hea[hole] = hea[hole/2];
    hole = hole/2;
  }

  hea[hole] = placeholder;
}

huffnode* heap::deleteMin(){
  if(heapsize == 0){
    throw "invalid operation on empty heap";
  }
  huffnode* newnode = new huffnode;

  newnode = hea[1];

  hea[1] = hea[heapsize--];

  hea.pop_back();

  percolateDown(1);

  return newnode;
}

void heap::percolateDown(int hole){
  huffnode* placeholder = hea[hole];
  int x = placeholder->getFreq();

  while(hole*2 <= heapsize){
    int child = hole*2;
    if((child + 1 <= heapsize) && (hea[child+1]->getFreq() < hea[child]->getFreq())){
      child = child + 1;
    }
    if(x > hea[child]->getFreq()){
      hea[hole] = hea[child];
      hole = child;
    }
    else{
      break;
    }
  }

  hea[hole] = placeholder;
}

huffnode* heap::findMin(){
  if(heapsize == 0){
    throw "invalid operation on empty heap";
  }
  return hea[1];
}

int heap::size(){
  return heapsize;
}

void heap::makeEmpty(){
  heapsize = 0;
  hea.resize(1);
}

bool heap::isEmpty(){
  return heapsize == 0;
}

void heap::generateCode(huffnode* tree, string code){
  if(tree->character != 0){
    if(tree->left != NULL || tree->right != NULL){

      //fixing tree
      tree->left = NULL;
      tree->right = NULL;
      generateCode(tree, code);
    }
  }

  if(tree->left != NULL && tree->right != NULL){
    generateCode(tree->left, code + "0");
    generateCode(tree->right, code + "1");
  }

  if(tree->left != NULL && tree->right == NULL){
    generateCode(tree->left, code + "0");
  }
  if(tree->right != NULL && tree->left == NULL){
    generateCode(tree->right, code + "1");
  }

  if(tree->left == NULL && tree->right == NULL){
    myMap.insert(std::pair<char,string>(tree->character,code));
  }
}

map<char,string> heap::getMap(){
  return this->myMap;
}

void heap::consolidate(){
  huffnode *newnode = new huffnode;
  newnode->insert(this->deleteMin());
  //newnode->left = this->deleteMin();
  //newnode->frequency = newnode->left->frequency;
  //cout << "I am also adding " << this->findMin()->character << endl;
  //newnode->right = this->deleteMin();
  //newnode->frequency = newnode->frequency + newnode->right->frequency;
  newnode->insert(this->deleteMin());


  this->insert(newnode);
}
