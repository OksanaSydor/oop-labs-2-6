#include "Student.h"
#include <iostream>

using namespace std;

int Student::amount = 0;

Student::Student(string name, int age, string faculty) : Person(name, age), faculty(faculty)
{
  amount++;
  id = amount;
  cout << "Student created via parameters" << endl;
}

Student::Student(const Student &other) : Person(other.GetName(), other.GetAge())
{
  faculty = other.faculty;
  amount++;
  id = amount;
  cout << "Copy constructor was called" << endl;
}

Student::Student(Student &&other) noexcept : Person(other.GetName(), other.GetAge()), faculty(move(other.faculty)), id(other.id)
{
  cout << "Move constructor was called" << endl;
}

int Student::GetId() const
{
  return id;
}

Student::~Student()
{
  cout << "Student destroyed" << endl;
}

void Student::showInfo()
{
  Person::showInfo();
  cout << "Faculty: " << faculty << endl;
}

void Student::operator++()
{
  SetAge(GetAge() + 1);
}

bool Student::operator==(const Student &other)
{
  return GetName() == other.GetName() && faculty == other.faculty;
}

ostream &operator<<(ostream &os, const Student &student)
{
  os << "Name: " << student.GetName() << endl;
  os << "Age: " << student.GetAge() << endl;
  os << "Faculty: " << student.faculty << endl;

  return os;
}

istream &operator>>(istream &is, Student &student)
{
  string name;
  int age;

  cout << "Enter name: ";
  is >> name;
  student.SetName(name);

  cout << "Enter age: ";
  is >> age;
  student.SetAge(age);

  cout << "Enter faculty: ";
  is >> student.faculty;

  return is;
}