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

void Master::showInfo()
{
  Student::showInfo();
  cout << "Bachelor specialty: " << bachelorSpec << endl;
  cout << "Scholarship: " << (scholarship ? "Yes" : "No") << endl;
}

void Master::study() const
{
  cout << "Master studies." << endl;
}

Master::Master(Master &&other) noexcept : Student(move(other)), bachelorSpec(move(other.bachelorSpec)), scholarship(other.scholarship)
{
  cout << "Master move constructor called" << endl;
}

Master::~Master()
{
  cout << "Master destroyed" << endl;
}