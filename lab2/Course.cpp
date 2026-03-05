#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string name, string code, int credits, int hours) : name(name), code(code), credits(credits), hours(hours)
{
  this->name = name;
  this->code = code;
  this->credits = credits;
  this->hours = hours;
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