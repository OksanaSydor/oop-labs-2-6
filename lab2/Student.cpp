#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
  cout << "Student created" << endl;
}

Student::Student(string name, int age, string faculty) : name(name), age(age), faculty(faculty)
{
  this->age = age;
  this->faculty = faculty;

  cout << "Student created via parameters" << endl;
}

Student::Student(string name)
{
  this->name = name;
  this->age = 0;
  this->faculty = "Unknown";

  cout << "Student created via parameter \"name\"" << endl;
}

Student::~Student()
{
  cout << "Student destroyed" << endl;
}

void Student::showInfo()
{
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Faculty: " << faculty << endl;
}