#ifndef TREENODE_H
#define TREENODE_H
#include <string>

using namespace std;

class treenode {
 public:
  treenode();
  treenode(char c, int f);
  ~treenode();
  void insert(char c, int f);
  void changeFreq(int change);
  void insert(char c, int f, char cc int ff
  int getFreq();
  char getChar();
  void changeLeft(treenode *newone);
  void changeRight(treenode *newone);
  bool isLess(treenode *other);

  void printTree(treenode* whichone, string current);


 private:
  friend class heap;
  char character;
  int frequency;
  treenode *left;
  treenode *right;
  
  
};
#endif
