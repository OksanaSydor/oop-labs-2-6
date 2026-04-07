#include "Bachelor.h"
#include <iostream>

using namespace std;

Bachelor::Bachelor(bool scholarship, string name, int age) : Student(name, age, "Unknown"), scholarship(scholarship)
{
  cout << "Bachelor constructor called." << endl;
}

Bachelor::Bachelor(bool scholarship) : Student("Unknown", 0, "Unknown"), scholarship(scholarship)
{
  cout << "Bachelor constructor called" << endl;
}

bool Bachelor::IsOnScholarship()
{
  return scholarship;
}

Bachelor::Bachelor(const Bachelor &other) : Student(other), scholarship(other.scholarship)
{
  cout << "Bachelor copy constructor called" << endl;
}

void Bachelor::isAdult()
{
  if (age < 18)
  {
    cout << "Bachelor is underage." << endl;
  }
  else
  {
    cout << "Bachelor is adult." << endl;
  }
}

void Bachelor::showInfo()
{
  Student::showInfo();
  cout << "Scholarship: " << (scholarship ? "Yes" : "No") << endl;
}

void Bachelor::study() const
{
  cout << "Bachelor studies." << endl;
}

Bachelor &Bachelor ::operator=(const Bachelor &other)
{
  if (this != &other)
  {
    scholarship = other.scholarship;
  }
  cout << "Bachelor operator= called" << endl;
  return *this;
}

Bachelor::~Bachelor()
{
  cout << "Bachelor destroyed" << endl;
}