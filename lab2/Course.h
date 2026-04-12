#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
protected:
  string name;
  string code;
  int credits;
  int hours;

public:
  Course(string name = "Unknown", string code = "Unknown", int credits = 0, int hours = 0);
  virtual ~Course();

  string GetName() const;
  string GetCode() const;
  int GetCredits() const;
  int GetHours() const;

  virtual void showInfo();
};

#endif