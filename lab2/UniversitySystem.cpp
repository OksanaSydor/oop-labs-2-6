#include "UniversitySystem.h"
#include <iostream>

using namespace std;

void UniversitySystem::launch()
{
  FileManager::loadStudents(students);
  FileManager::loadTeachers(teachers);
  FileManager::loadCourses(courses);
  FileManager::loadSchedule(schedule);

  int choice;

  while (true)
  {
    cout << "\n1. Add student\n";
    cout << "2. Show students\n";
    cout << "3. Save and exit\n";

    cin >> choice;

    if (choice == 1)
    {
      string name, faculty;
      int age;

      cout << "Name: ";
      cin >> name;

      cout << "Age: ";
      cin >> age;

      cout << "Faculty: ";
      cin >> faculty;

      students.push_back(make_unique<Student>(name, age, faculty));
    }
    else if (choice == 2)
    {
      for (auto &s : students)
      {
        s->showInfo();
        cout << endl;
      }
    }
    else if (choice == 3)
    {
      FileManager::saveStudents(students);
      FileManager::saveTeachers(teachers);
      FileManager::saveCourses(courses);
      FileManager::saveSchedule(schedule);

      break;
    }
  }
}