#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

using namespace std;

int main()
{
  Student s1("Oksana", 18, "Educational and Scientific Institute of Physical, Technical and Computer Sciences");
  Student s2("Anna");

  s1.showInfo();
  s2.showInfo();

  Teacher t1("Albert", "Faculty of foreign languages", 20);
  Teacher t2("Anastasia");
  Teacher t3;

  t1.showInfo();
  t2.showInfo();
  t3.showInfo();

  Course c1("Software Engeneering");

  c1.showInfo();

  return 0;
}