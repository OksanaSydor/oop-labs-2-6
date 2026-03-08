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
  void operator++();
  bool operator==(const Student &other);

  void showInfo();
  int GetId() const;
  static int GetAmount()
  {
    return amount;
  }
  friend ostream &operator<<(ostream &os, const Student &student);
  friend istream &operator>>(istream &is, Student &student);
};

#endif