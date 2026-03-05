#include "Teacher.h"
#include <iostream>

using namespace std;

Teacher::Teacher(string name, string department, int experienceYears) : name(name), department(department), experienceYears(experienceYears)
{
  this->name = name;
  this->department = department;
  this->experienceYears = experienceYears;

  cout << "Teacher created via parameters" << endl;
}

Teacher::~Teacher()
{
  cout << "Teacher destroyed" << endl;
}

void Teacher::showInfo()
{
  cout << "Name: " << name << endl;
  cout << "Department: " << department << endl;
  cout << "Experience years: " << experienceYears << endl;
}