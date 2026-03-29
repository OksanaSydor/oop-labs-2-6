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

Master::Master(Master &&other) noexcept : Student(move(other)), bachelorSpec(move(other.bachelorSpec)), scholarship(other.scholarship)
{
  cout << "Master move constructor called" << endl;
}

Master::~Master()
{
  cout << "Master destroyed" << endl;
}