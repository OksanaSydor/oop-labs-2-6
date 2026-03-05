#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
  cout << "Student created" << endl;
}

Student::~Student(){
  cout<< "Student destroyed"<< endl;
}

void Student::showInfo(){
  cout << "Student info" << endl;
}