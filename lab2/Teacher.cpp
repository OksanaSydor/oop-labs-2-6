#include "Teacher.h"
#include <iostream>

using namespace std;

Teacher::Teacher(string name, int age, string department, int experienceYears) : name(name), age(age), department(department), experienceYears(experienceYears)
{
  cout << "Teacher created via parameters" << endl;
}

Teacher::~Teacher()
{
  cout << "Teacher destroyed" << endl;
}

string Teacher::GetName() const
{
  return name;
}

int Teacher::GetAge() const
{
  return age;
}

void Teacher::SetName(string name)
{
  this->name = name;
}

void Teacher::SetAge(int age)
{
  this->age = age;
}

string Teacher::GetDepartment() const
{
  return department;
}

int Teacher::GetExperienceYears() const
{
  return experienceYears;
}

void Teacher::showInfo()
{
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Department: " << department << endl;
  cout << "Experience years: " << experienceYears << endl;
}