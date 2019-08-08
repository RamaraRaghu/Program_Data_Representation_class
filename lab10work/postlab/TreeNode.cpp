//Rakshith Raghu, rr5de
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"
#include <iostream>

//Default Constructor -left and right are NULL, value '?'
TreeNode::TreeNode() {
    value="?";
    left=NULL;
    right=NULL;
}

//Constructor - sets value to val
TreeNode::TreeNode(const string & val) {
    value=val;
    left=NULL;
    right=NULL;
}

bool TreeNode::insert(string code, string character){
  string temp = code;
  //asks base case
  if(code.length() == 1){
    TreeNode * newnode = new TreeNode(character);
    if(code.at(0) == '0'){
      this->left = newnode;
      return true;
    }
    if(code.at(0) == '1'){
      this->right = newnode;
      return true;
    }
  }

  if(code.at(0) == '1'){
    if(this->right == NULL){
      TreeNode * newnode = new TreeNode;
      this->right = newnode;
    }
    temp.erase(0,1);
    return this->right->insert(temp, character);
  }
  if(code.at(0) == '0'){
    if(this->left == NULL){
      TreeNode * newnode = new TreeNode;
      this->left = newnode;
    }
    temp.erase(0,1);
    return this->left->insert(temp, character);
  }
  return false; 
}

string TreeNode::generateString(string code){
  //base case to get output when 1 above a leaf
  if(code.length() == 1){
    if(code.at(0) == '0'){
      return this->left->value;
    }
    else{
      return this->right->value;
    }
  }

  if(code.at(0) == '0'){
    string temp = code;
    temp.erase(0,1);
    return this->left->generateString(temp);
  }
  if(code.at(0) == '1'){
    string temp = code;
    temp.erase(0,1);
    return this->right->generateString(temp);
  }

  return "NOT_DECODED";

  
}
