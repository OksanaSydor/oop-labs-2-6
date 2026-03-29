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

Bachelor::~Bachelor()
{
  cout << "Bachelor destroyed" << endl;
}