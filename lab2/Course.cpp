#include "Course.h"
#include <iostream>

using namespace std;

Course::Course()
{
  cout << "Course created" << endl;
}

Course::~Course()
{
  cout << "Course destroyed" << endl;
}

void Course::showInfo()
{
  cout << "Name:" << name << endl;
  cout << "Code:" << code << endl;
  cout << "Credits amount:" << credits << endl;
  cout << "Hours amount:" << hours << endl;
}