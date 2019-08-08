/*
 * Filename: List.h
 * Description: List class definition
 * 	also includes the prototype for non-member function print()
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;

// When reading in ListItr.h first, it starts reading in this file
// before declaring that ListItr is a class.  This file then include
// ListItr.h, but beacuse of the #ifndef LISTITR_H statement, the code
// in that file is not read.  Thus, in this case, this List.h file
// will be read in, and will not know that ListItr is a class, which
// will cause compilation problems later on in this file.  Got it?
// Isn't C++ fun???

class stack {
public:
    stack();			 //Constructor
    ~stack();			//Destructor
    bool empty() const;		//Returns true if empty; else false
    void push(int x);	//Insert x at tail of list
    void pop();		//Removes the first occurrence of x
    int size() const; //Returns the number of elements in the list
    int top();

private:
    ListNode *head, *tail;	//indicates beginning and end of the list
    int count;			//#of elements in list
};

// printList: non-member function prototype
//prints list forwards when direction is true
//or backwards when direction is false
#endif
/* end of List.h */
