#include "Teacher.h"
#include <iostream>

using namespace std;

Teacher::Teacher(){
  cout << "Teacher created" << endl;
}

Teacher::~Teacher(){
  cout<< "Teacher destroyed"<< endl;
}

void Teacher::showInfo(){
  cout << "Teacher info" << endl;
}