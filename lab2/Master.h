#ifndef MASTER_H
#define MASTER_H

#include "Student.h"
#include <string>
using namespace std;

class Master final : public Student
{
private:
  string bachelorSpec;
  bool scholarship;

public:
  Master(string bachelorSpec = "Unknown", bool scholarship = false);
  string GetBachelorSpec();
  bool IsOnScholarship();

  void showInfo() override;
  void study() const override final;

  Master(Master &&other) noexcept;
  virtual ~Master();
};

#endif