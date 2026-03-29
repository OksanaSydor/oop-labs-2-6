#include "Person.h"

Person::Person(string name, int age) : name(name), age(age)
{
  cout << "Person created" << endl;
}

Person::~Person()
{
  cout << "Person destroyed" << endl;
}

string Person::GetName() const
{
  return name;
}

int Person::GetAge() const
{
  return age;
}

void Person::SetName(string name)
{
  this->name = name;
}

void Person::SetAge(int age)
{
  this->age = age;
}

void Person::showInfo()
{
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
}