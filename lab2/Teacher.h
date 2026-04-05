#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "Person.h"

using namespace std;

class Teacher : public Person
{
private:
  string name;
  int age;
  string department;
  int experienceYears;

public:
  Teacher(string name = "Unknown", int age = 0, string department = "Unknown", int experienceYears = 0);
  virtual ~Teacher();

  string GetName() const override;
  int GetAge() const override;
  void SetName(string name) override;
  void SetAge(int age) override;

  void showInfo() override;
};

#endif