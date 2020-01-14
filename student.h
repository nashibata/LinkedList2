//header guards
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

//header file for the student class

using namespace std;

class Student{
 public:
  Student(const char*, int, float); //constructor
  ~Student(); //destructor
  char* getName();
  int getID();
  float getGPA();
 private:
  char name[50];
  int ID;
  float GPA;
};
#endif
