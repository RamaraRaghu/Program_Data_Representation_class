//Rakshith Raghu, rr5de, lifecycle.h, 9/4/2018

#ifndef LIFECYCLE_H
#define LIFECYCLE_H
using namespace std;
#include <iostream>
#include <string>

class MyObject {
 public:
  static int numObjs;
  MyObject(const char *n = "--default--");
  MyObject(const MyObject& rhs);
  ~MyObject();
  string getName() const{
    return name;
  }
  void setName(const string newName){
    name = newName;
  }
  friend ostream& operator<<(ostream& output, const MyObject& obj);
  
  /* int cmpMyObj(const MyObject o1, const MyObject o2);
  void swapMyObj(MyObject& o1, MyObject& o2);
  MyObject getMaxMyObj(const MyObject o1, const MyObject o2); */
 private:
  string name;
  int id;
};
#endif
  
