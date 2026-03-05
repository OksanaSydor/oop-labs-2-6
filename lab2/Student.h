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

public:
  Student();
  Student(string name, int age, string faculty);
  Student(string name);
  Student(string name = "Unknown", int age = 0, string faculty = "Unknown");
  ~Student();

  void showInfo();
};

#endif