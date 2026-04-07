#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "Person.h"
#include "Course.h"

using namespace std;

class Student : public Person
{
protected:
  string name;
  int age;
  string faculty;
  int id;
  static int amount;
  Course course;

public:
  Student(string name = "Unknown", int age = 0, string faculty = "Unknown");
  Student(const Student &other);
  Student(Student &&other) noexcept;
  virtual ~Student();

  void operator++();
  bool operator==(const Student &other);

  string GetName() const override;
  int GetAge() const override;
  void SetName(string name) override;
  void SetAge(int age) override;

  void showInfo() override;
  virtual void study() const;
  virtual void isAdult();

  int GetId() const;
  static int GetAmount()
  {
    return amount;
  }
  friend ostream &operator<<(ostream &os, const Student &student);
  friend istream &operator>>(istream &is, Student &student);
};

#endif