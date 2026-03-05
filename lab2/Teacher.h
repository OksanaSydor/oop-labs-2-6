#ifndef TEACHER_H
#define TEACHER_H

#include <string>
using namespace std;

class Teacher
{
private:
  string name;
  string department;
  int experienceYears;

public:
  Teacher(string name = "Unknown", string department = "Unknown", int experienceYears = 0);
  ~Teacher();

  void showInfo();
};

#endif