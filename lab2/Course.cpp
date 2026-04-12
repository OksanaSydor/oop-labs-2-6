#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string name, string code, int credits, int hours) : name(name), code(code), credits(credits), hours(hours)
{
}

Course::~Course()
{
  cout << "Course destroyed" << endl;
}

string Course::GetName() const
{
  return name;
}

string Course::GetCode() const
{
  return code;
}

int Course::GetCredits() const
{
  return credits;
}

int Course::GetHours() const
{
  return hours;
}

void Course::showInfo()
{
  cout << "Name:" << name << endl;
  cout << "Code:" << code << endl;
  cout << "Credits amount:" << credits << endl;
  cout << "Hours amount:" << hours << endl;
}