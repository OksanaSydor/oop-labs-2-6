#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
private:
  string name;
  int age;
  string faculty;
  int id;
  static int amount;

public:
  Student(string name = "Unknown", int age = 0, string faculty = "Unknown");
  Student(const Student &other);
  Student(Student &&other) noexcept;
  ~Student();

  void showInfo();
  int GetId();
  static int GetAmount()
  {
    return amount;
  }
};

#endif