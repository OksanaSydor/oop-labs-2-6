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
  cout << "Course info" << endl;
}