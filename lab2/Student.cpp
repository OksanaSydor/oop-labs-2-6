#include "Student.h"
#include <iostream>

using namespace std;

int Student::amount = 0;

Student::Student(string name, int age, string faculty) : Person(name, age), faculty(faculty), course("Unknown")
{
  amount++;
  id = amount;
  cout << "Student created via parameters" << endl;
}

Student::Student(const Student &other) : Person(other.name, other.age)
{
  faculty = other.faculty;
  amount++;
  id = amount;
  cout << "Copy constructor was called" << endl;
}

Student::Student(Student &&other) noexcept : Person(other.name, other.age), faculty(move(other.faculty)), id(other.id)
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
  cout << "Course info: ";
  course.showInfo();
  cout << endl;
}

void Student::operator++()
{
  age++;
}

bool Student::operator==(const Student &other)
{
  return name == other.name && faculty == other.faculty;
}

ostream &operator<<(ostream &os, const Student &student)
{
  os << "Name: " << student.name << endl;
  os << "Age: " << student.age << endl;
  os << "Faculty: " << student.faculty << endl;

  return os;
}

istream &operator>>(istream &is, Student &student)
{

  cout << "Enter name: ";
  is >> student.name;

  cout << "Enter age: ";
  is >> student.age;

  cout << "Enter faculty: ";
  is >> student.faculty;

  return is;
}