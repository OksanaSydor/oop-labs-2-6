#ifndef BACHELOR_H
#define BACHELOR_H

#include "Student.h"
using namespace std;

class Bachelor : public Student
{
private:
  bool scholarship;

public:
  Bachelor(bool scholarship = false);
  bool IsOnScholarship();
  Bachelor(const Bachelor &other);
  Bachelor &operator=(const Bachelor &other);
  ~Bachelor();
};

#endif