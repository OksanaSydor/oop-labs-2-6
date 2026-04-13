#include "Student.h"
#include <iostream>

using namespace std;

int Student::amount = 0;

Student::Student(string name, int age, string faculty) : name(name), age(age), faculty(faculty), course("Unknown")
{
  amount++;
  id = amount;
  cout << "Student created via parameters" << endl;
}

Student::Student(const Student &other) : name(other.name), age(other.age), faculty(other.faculty), course(other.course)
{
  amount++;
  id = amount;
  cout << "Copy constructor was called" << endl;
}

Student::Student(Student &&other) noexcept : name(move(other.name)), age(other.age), faculty(move(other.faculty)), id(other.id), course(other.course)
{
  cout << "Move constructor was called" << endl;
}

int Student::GetId() const
{
  return id;
}

string Student::GetName() const
{
  return name;
}

int Student::GetAge() const
{
  return age;
}

void Student::SetName(string name)
{
  this->name = name;
}

void Student::SetAge(int age)
{
  this->age = age;
}

void Student::SetCourse(const Course &c)
{
  course = c;
}

string Student::GetFaculty() const
{
  return faculty;
}

Course Student::GetCourse() const
{
  return course;
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
  cout << "Course info: \n";
  course.showInfo();
  cout << endl;
}

void Student::study() const
{
  cout << "Student studies." << endl;
}

void Student::isAdult()
{
  if (age < 18)
  {
    cout << "Student is underage." << endl;
  }
  else
  {
    cout << "Student is adult." << endl;
  }
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