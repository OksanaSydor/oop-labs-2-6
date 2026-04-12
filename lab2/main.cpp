#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "OnlineCourse.h"
#include "Bachelor.h"
#include "Master.h"
#include "Person.h"
#include "UniversitySystem.h"

using namespace std;

Student createStudent()
{
  Student temp("Max", 20, "Math");
  return temp;
}

void staticBindingProblem(Person *person)
{
  person->showInfo();
}

int main()
{
  Student s1("Oksana", 18, "Educational and Scientific Institute of Physical, Technical and Computer Sciences");
  Student s2("Anna");

  s1.showInfo();
  s2.showInfo();

  Teacher t1("Albert", 50, "Faculty of foreign languages", 20);
  Teacher t2("Anastasia", 30);
  Teacher t3;

  t1.showInfo();
  t2.showInfo();
  t3.showInfo();

  Course c1("Software Engeneering");

  c1.showInfo();

  cout << "Copy s2 from s1" << endl;
  Student s3 = s1;
  s1.showInfo();
  s2.showInfo();

  Student s4 = createStudent();

  cout << "Student created by move constructor: " << endl;
  s3.showInfo();

  cout << s1.GetId() << endl;
  cout << s2.GetId() << endl;
  cout << s3.GetId() << endl;
  cout << s4.GetId() << endl;

  cout << "Amount of students: " << Student::GetAmount() << endl;

  ++s1;
  s1.showInfo();

  if (s1 == s2)
  {
    cout << "Students s1 and s2 are the same" << endl;
  }

  if (s1 == s3)
  {
    cout << "Students s1 and s3 are the same" << endl;
  }

  Student s5;
  cin >> s5;
  cout << s5;

  Bachelor b(false);
  if (b.IsOnScholarship())
  {
    cout << "Bachelor draws scholarship" << endl;
  }
  else
  {
    cout << "Bachelor doesn`t draw scholarship" << endl;
  }

  Master m("Math", true);
  if (m.IsOnScholarship())
  {
    cout << "Master draws scholarship" << endl;
  }
  else
  {
    cout << "Master doesn`t draw scholarship" << endl;
  }

  cout << m.GetBachelorSpec() << endl;

  Bachelor b2 = b;
  Bachelor b3("Economics");
  Bachelor b4("Physics");

  b3 = b4;
  b3.showInfo();

  Master m2 = move(m);

  cout << "--------lab 5--------" << endl;

  cout << "\n------Static Method Binding-----" << endl;

  OnlineCourse oc("IT");
  Course *poc = &oc;

  cout << "Called showInfo() through * type Course to object type OnlineCourse: " << endl;
  poc->showInfo();

  cout << "------------------------------" << endl;

  cout << "Called showInfo() through object type OnlineCourse: " << endl;
  oc.showInfo();

  cout << "-----Demonstration Run-time polymorphism through Base class pointer-----" << endl;

  Bachelor b1(true);
  Master m1("Computer Science", true);

  Student *pb1 = &b1;
  Student *pm1 = &m1;

  pb1->showInfo();
  pb1->study();

  pm1->showInfo();
  pm1->study();

  cout << "----------------------------" << endl;

  Bachelor astud(true, "Kate", 20);
  Bachelor ustud(true, "Maria", 17);
  Master mast("Math");

  Student *pastud = &astud;
  Student *pustud = &ustud;
  Student *pmast = &mast;

  pastud->isAdult();
  pustud->isAdult();
  pmast->isAdult();

  cout << "-----Demonstration Run-time polymorphism through Base class reference-----" << endl;

  Student &b1Ref = b1;
  Student &m1Ref = m1;

  b1Ref.showInfo();
  b1Ref.study();

  m1Ref.showInfo();
  m1Ref.study();

  cout << "-----Interface demonstration-----" << endl;
  Student st("Ira", 21, "IT");
  Teacher tr("Anna", 42, "Computer Science", 14);

  Person *pst = &st;
  Person *ptr = &tr;
  Person *ppb1 = &b1;
  Person *ppm1 = &m1;

  pst->showInfo();
  cout << endl;
  ptr->showInfo();
  cout << endl;
  ppb1->showInfo();
  cout << endl;
  ppm1->showInfo();
  cout << endl;

  cout << "-----------Lab 6-----------" << endl;

  UniversitySystem us;
  us.launch();

  return 0;
}