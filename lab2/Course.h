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
  Course();
  ~Course();

  void showInfo();
};

#endif