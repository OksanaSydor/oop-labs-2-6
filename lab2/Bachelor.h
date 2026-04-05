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

  void showInfo() override;
  void study() const override;

  Bachelor(const Bachelor &other);
  Bachelor &operator=(const Bachelor &other);
  virtual ~Bachelor();
};

#endif