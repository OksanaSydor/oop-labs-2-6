#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Bachelor.h"
#include "Master.h"
#include "Person.h"

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

  Person p("Tom", 40);
  p.showInfo();

  Bachelor b2 = b;
  Bachelor b3("Economics");
  Bachelor b4("Physics");

  b3 = b4;
  b3.showInfo();

  Master m2 = move(m);

  cout << "--------lab 5--------" << endl;

  Student st("Ira", 21, "IT");
  Teacher tr("Anna", 42, "Computer Science", 14);

  Person *pst = &st;
  Person *ptr = &tr;

  cout << "Called showInfo() through * type Person to object type Student: " << endl;
  pst->showInfo();

  cout << "Called showInfo() through * type Person to object type Teacher: " << endl;
  ptr->showInfo();

  cout << "------------------------------" << endl;

  cout << "Called showInfo() through object type Student: " << endl;
  st.showInfo();

  cout << "Called showInfo() through object type Teacher: " << endl;
  tr.showInfo();

  return 0;
}