#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "Person.h"

using namespace std;

class Teacher : public Person
{
private:
  string department;
  int experienceYears;

public:
  Teacher(string name = "Unknown", int age = 0, string department = "Unknown", int experienceYears = 0);
  ~Teacher();

  void showInfo();
};

#endif