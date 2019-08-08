// TreeNode.h: TreeNode class definition
//Rakshith Raghu rr5de
// CS 2150: Lab 10


#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode();						//Default Constructor
    TreeNode(const string & val);	//Constructor
    bool insert(string code, string character);
    string generateString(string code);

private:
    string value;
    TreeNode *left, *right;			// for trees
};

#endif
