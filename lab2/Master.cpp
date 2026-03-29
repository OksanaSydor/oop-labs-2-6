#include "Master.h"
#include <iostream>

using namespace std;

Master::Master(string bachelorSpec, bool scholarship) : Student("Unknown", 0, "Unknown"), bachelorSpec(bachelorSpec), scholarship(scholarship)
{
  cout << "Master constructor called" << endl;
}

bool Master::IsOnScholarship()
{
  return scholarship;
}

string Master::GetBachelorSpec()
{
  return bachelorSpec;
}

Master::~Master()
{
  cout << "Master destroyed" << endl;
}