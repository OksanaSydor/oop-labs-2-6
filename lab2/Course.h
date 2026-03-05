#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
private:
  string name;
  string code;
  int credits;
  int hours;

public:
  Course(string name = "Unknown", string code = "Unknown", int credits = 0, int hours = 0);
  Course();
  ~Course();

  void showInfo();
};

#endif