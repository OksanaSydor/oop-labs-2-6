#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
  virtual string GetName() const = 0;
  virtual int GetAge() const = 0;
  virtual void SetName(string name) = 0;
  virtual void SetAge(int age) = 0;
  virtual void showInfo() = 0;

  virtual ~Person();
};

#endif