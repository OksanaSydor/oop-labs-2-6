#include "Student.h"
#include <iostream>

using namespace std;

int Student::amount = 0;

Student::Student(string name, int age, string faculty) : name(name), age(age), faculty(faculty)
{
  amount++;
  id = amount;
  cout << "Student created via parameters" << endl;
}

Student::Student(const Student &other)
{
  this->name = other.name;
  this->age = other.age;
  this->faculty = other.faculty;
  amount++;
  id = amount;
  cout << "Copy constructor was called" << endl;
}

Student::Student(Student &&other) noexcept : name(move(other.name)), age(other.age), faculty(move(other.faculty)), id(other.id)
{
  cout << "Move constructor was called" << endl;
}

int Student::GetId()
{
  return id;
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