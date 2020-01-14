#ifndef NODE_H
#define NODE_H

//NODE HEADER FILE, declares all functions and variables in Node class
#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public://functions of Node, function prototype format
  Node(Student* newstudent);//Constructor
  ~Node();//Destructor
  void setNext(Node* newnext);//set next pointer to current
  Node* getNext();//get next node pointer
  void setStudent(Student* newstudent); //set student
  Student* getStudent();//get Student pointer
 private://variables of Node class
  Student* student;
  Node* next;
};

#endif
