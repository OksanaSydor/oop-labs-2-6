#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string name, int age, string faculty) : name(name), age(age), faculty(faculty)
{
  cout << "Student created via parameters" << endl;
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