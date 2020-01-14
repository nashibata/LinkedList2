#include <iostream>
#include <cstring>

#include "student.h"

using namespace std;

Student::Student(const char* newname, int newID, float newGPA) {
  strcpy(name, newname);
  ID = newID;
  GPA = newGPA;
}

Student::~Student() {
  delete &name;
}

char* Student::getName() {
  return name;
}

int Student::getID() {
  return ID;
}

float Student::getGPA() {
  return GPA;
}
