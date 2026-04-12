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
    cout << "\n---------- Menu ----------\n";
    cout << "1. Log in as administrator\n";
    cout << "2. User menu\n";
    cout << "3. Save and exit\n";

    cin >> choice;

    if (choice == 1)
    {
      string password;
      cout << "Enter password: ";
      cin >> password;

      if (password == adminPassword)
      {
        adminMenu();
      }
      else
      {
        cout << "Wrong password.\n";
      }
    }
    else if (choice == 2)
    {
      userMenu();
    }
    else if (choice == 3)
    {
      FileManager::saveStudents(students);
      FileManager::saveTeachers(teachers);
      FileManager::saveCourses(courses);
      FileManager::saveSchedule(schedule);

      cout << "Data saved!" << endl;

      break;
    }
  }
}

void UniversitySystem::adminMenu()
{
  int choice;

  while (true)
  {
    cout << "\n---------- Admin Menu ----------\n";
    cout << "1.Add student\n";
    cout << "2.Show information about students\n";
    cout << "3.Save data\n";
    cout << "0.Back\n";

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

      cout << "Student added.\n";
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
      cout << "Data saved!" << endl;
    }
    else if (choice == 0)
    {
      break;
    }
  }
}

void UniversitySystem::userMenu()
{
  int choice;

  while (true)
  {
    cout << "\n---------- User Menu ----------\n";
    cout << "1. Show information about students\n";
    cout << "2. Show information about courses\n";
    cout << "3. Show schedule\n";
    cout << "0. Back\n";

    cin >> choice;

    if (choice == 1)
    {
      for (auto &s : students)
      {
        s->showInfo();
        cout << endl;
      }
    }
    else if (choice == 2)
    {
      for (auto &c : courses)
      {
        c->showInfo();
        cout << endl;
      }
    }
    else if (choice == 3)
    {
      for (auto &s : schedule)
      {
        s->showInfo();
        cout << endl;
      }
    }
    else if (choice == 0)
    {
      break;
    }
  }
}