#ifndef MASTER_H
#define MASTER_H

#include "Student.h"
#include <string>
using namespace std;

class Master : public Student
{
private:
  string bachelorSpec;
  bool scholarship;

public:
  Master(string bachelorSpec = "Unknown", bool scholarship = false);
  string GetBachelorSpec();
  bool IsOnScholarship();
  ~Master();
};

#endif