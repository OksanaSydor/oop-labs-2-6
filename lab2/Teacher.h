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
  Teacher();
  ~Teacher();

  void showInfo();
};

#endif