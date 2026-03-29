#include "Teacher.h"
#include <iostream>

using namespace std;

Teacher::Teacher(string name, int age, string department, int experienceYears) : Person(name, age), department(department), experienceYears(experienceYears)
{
  cout << "Teacher created via parameters" << endl;
}

Teacher::~Teacher()
{
  cout << "Teacher destroyed" << endl;
}

void Teacher::showInfo()
{
  Person::showInfo();
  cout << "Department: " << department << endl;
  cout << "Experience years: " << experienceYears << endl;
}