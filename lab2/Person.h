#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person
{
private:
  string name;
  int age;

public:
  Person(string name = "Unknown", int age = 0);

  string GetName() const;
  int GetAge() const;
  void SetName(string name);
  void SetAge(int age);
  void showInfo();

  ~Person();
};

#endif