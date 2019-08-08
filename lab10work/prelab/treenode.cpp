#include "treenode.h"
#include <iostream>
#include <string>

treenode::treenode(){
  //serves as head node
  character = '\0';
  frequency = 0;
  left = NULL;
  right = NULL; 
}

treenode::treenode(char c, int f){
  //serves as a node with character
  character = c;
  frequency = f;
}

treenode::~treenode(){
}

char treenode::getChar(){
  return this->character;
}

void treenode::changeLeft(treenode *newone){
  this->left = newone;
}

void treenode::changeRight(treenode *newone){
  this->right = newone;
}

void treenode::changeChild(treenode *newleft, treenode *newright){
  this->right = newright;
  this->left = newleft;
}

int treenode::getFreq(){
  return this->frequency;
}

void treenode::changeFreq(int change){
  this->frequency = change;
}

bool treenode::isLess(treenode *other){
  int o = other->frequency;
  int c = this->frequency;

  if(c < o){
    return true;
  }
  else{
    return false;
  }
}

void treenode::printTree(treenode* whichone, string current){
  if(this->left != NULL){
    string currenter = current + "0";
    printTree(this->left, currenter); 
  }

  if(this->right != NULL){
    string currenting = current + "1";
    printTree(this->right, currenting);
  }

  if(this->right == NULL && this->left == NULL){
    if(this->character != ' '){
      cout << this->character << " " << current << endl;
    }
    else{
      cout << "space " << current << endl;
    }
  }
}
