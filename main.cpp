#include <iostream>
#include <iomanip>
#include <cstring>

#include "node.h"
#include "student.h"

using namespace std;

Node* head = NULL;

void add(Node* current, char* name, int id, float gpa) {
  //add function taken from Tpanda03, he gave me advice on how to order nodes
  Student* student = new Student(name, id, gpa);

  if (head == NULL) { //first node
    head = new Node(student);
  }
  else if (student->getID() < head->getStudent()->getID()) { //if the second inputted ndoe is less than the head node, make that the head node
    Node* temp = new Node(head->getStudent());
    temp->setNext(head->getNext());
    head->setStudent(student);
    head->setNext(temp);
  }
  else if (current->getNext() == NULL) { //if next doesn't exist
    Node* New = new Node(student);
    current->setNext(New);
  }
  else if (student->getID() < current->getNext()->getStudent()->getID()) { //if the new node is less than the current node, set it to current's next
    Node* New = new Node(student);
    New->setNext(current->getNext());
    current->setNext(New);
  }
  else {
    add(current->getNext(), name, id, gpa);
  }
}

void print(Node* a) {
  if (a == head) {
    cout << "list:" << endl;
  }
  if (a != NULL) {
    cout << "/ Name: " << a->getStudent()->getName();
    cout << ", ID: " << a->getStudent()->getID();
    cout << ", GPA: " << fixed << setprecision(2) << a->getStudent()->getGPA() << endl;
    print(a->getNext()); //recursive function
  }
}

float average(Node* next) {
  float total = 0;
  int count = 0;
  if (next == head) {
    total += next -> getNext() -> getStudent() -> getGPA();
    count += 1;
  }
  while (next -> getNext() != NULL) {
      total += next -> getNext() -> getStudent() -> getGPA();
      count += 1;
      next = next -> getNext();
  }
  return (total/count);
}

void deleteNode(Node* &start, int id) {
  Node* current = start;
  if (current != NULL) {
  if(current->getStudent()->getID() == id) {
    Node* kill = start;
    start = start->getNext();
    cout << "deleting kill" << endl;
    delete kill;
    cout << "deleted kill" << endl;
  }
  else {
    if(current->getNext()->getStudent()->getID() == id){
      Node* target = current->getNext();
      current->setNext(target->getNext());
      cout << "deleting target" << endl;
      delete target;
      cout << "deleted target" << endl;
    }
    else {
      current = current->getNext();
      deleteNode(current, id);
    }
  }
  }
  else {
    cout << "List is empty" << endl;
  }
}

int main() {
  bool running = true;

  while (running == true) {
    int count = 0;
    char input[50];
    char name[50];
    int id = 0;
    float gpa = 0.00;
    cout << "What is your command? (add, delele, exit, average, print)" << endl;
    cin.get(input, 50);
    cin.clear();
    cin.ignore(100, '\n');

    if (strcmp(input, "add") == 0) {
      cout << "Please anwer the following..." << endl;
      cout << "Name?" << endl;
      cin.get(name, 50);
      cin.clear();
      cin.ignore(100, '\n');

      cout << "ID?" << endl;
      cin >> id;
      cin.clear();
      cin.ignore(100, '\n');

      cout << "GPA?" << endl;
      cin >> gpa;
      cin.clear();
      cin.ignore(100, '\n');

      add(head, name, id, gpa);
      print(head);
      count++;
    }
    else if (strcmp(input, "print") == 0) {
      print(head);
    }
    else if (strcmp(input, "exit") == 0) {
      cout << "Thanks for playing!" << endl;
      running = false;
    }
    else if (strcmp(input, "delete") == 0) {
      cout << "enter id of deletion" << endl;
      int id = 0;
      cin >> id;
      cin.ignore(50, '\n');
      deleteNode(head, id);
      print(head);
    }
    else if (strcmp(input, "average") == 0) {
      if (head == NULL) {
	cout << "No students to average." << endl;
      }
      else {
	cout << "Average: " << average(head) << endl;
      }
    }
  }
}
