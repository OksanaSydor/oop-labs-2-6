#include "Bachelor.h"
#include <iostream>

using namespace std;

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