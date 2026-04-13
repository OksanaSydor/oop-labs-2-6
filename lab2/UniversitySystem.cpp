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
    try
    {
      cout << "\n---------- Menu ----------\n";
      cout << "1. Log in as administrator\n";
      cout << "2. User menu\n";
      cout << "3. Exit\n";

      cin >> choice;

      if (choice == 1)
      {
        string password;
        cout << "Enter password: ";
        cin >> password;

        if (password == adminPassword)
        {
          History::addRecord("Admin logged in.", adminHistoryFile);
          adminMenu();
        }
        else
        {
          cout << "Wrong password.\n";
          History::addRecord("Failed admin login.", adminHistoryFile);
        }
      }
      else if (choice == 2)
      {
        userMenu();
      }
      else if (choice == 3)
      {
        break;
      }
    }
    catch (exception &e)
    {
      cout << "Error: " << e.what() << endl;
    }
  }
}

void UniversitySystem::adminMenu()
{
  int choice;

  while (true)
  {
    try
    {
      cout << "\n---------- Admin Menu ----------\n";
      cout << "1. Add student\n";
      cout << "2. Add teacher\n";
      cout << "3. Add course\n";
      cout << "4. Add lesson to schedule\n";
      cout << "5. Show information about students\n";
      cout << "6. Show information about teachers\n";
      cout << "7. Show information about courses\n";
      cout << "8. Show schedule\n";
      cout << "9. Delete student\n";
      cout << "10. Delete teacher\n";
      cout << "11. Delete course\n";
      cout << "12. Delete lesson\n";
      cout << "13. Save data\n";
      cout << "14. View history\n";
      cout << "15. Delete history\n";
      cout << "16. Check students age (adult/underage)\n";
      cout << "17. Show students' IDs\n";
      cout << "18. Show number of students\n";
      cout << "0. Back\n";

      cin >> choice;

      if (choice == 1)
      {
        string name, faculty;
        int age;

        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        if (name.empty())
        {
          throw runtime_error("Invalid data!");
        }

        cout << "Age: ";
        cin >> age;
        if (age < 0)
        {
          throw runtime_error("Invalid data!");
        }

        cout << "Faculty: ";
        cin >> faculty;
        cout << endl;

        for (int i = 0; i < courses.size(); i++)
        {
          cout << i << ". ";
          courses[i]->showInfo();
          cout << endl;
        }

        int index;
        cout << "Choose course index: ";
        cin >> index;
        if (index < 0 || index >= courses.size())
        {
          throw runtime_error("Invalid data!");
        }

        auto student = make_unique<Student>(name, age, faculty);
        student->SetCourse(*courses[index]);

        students.push_back(move(student));

        cout << "Student added.\n";
        History::addRecord("Admin added student: " + name, adminHistoryFile);
      }
      else if (choice == 2)
      {
        string name, department;
        int age, experience;

        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        if (name.empty())
        {
          throw runtime_error("Invalid data!");
        }

        cout << "Age: ";
        cin >> age;
        if (age < 0)
        {
          throw runtime_error("Invalid data!");
        }

        cout << "Department: ";
        cin >> department;

        cout << "Experience years: ";
        cin >> experience;
        if (experience < 0)
        {
          throw runtime_error("Invalid data!");
        }

        teachers.push_back(make_unique<Teacher>(name, age, department, experience));

        cout << "Teacher added.\n";
        History::addRecord("Admin added teacher.", adminHistoryFile);
      }
      else if (choice == 3)
      {
        string name, code;
        int credits, hours;

        cout << "Course name: ";
        cin >> name;

        cout << "Code: ";
        cin >> code;

        cout << "Number of credits: ";
        cin >> credits;
        if (credits < 0)
        {
          throw runtime_error("Invalid data!");
        }

        cout << "Number of hours: ";
        cin >> hours;
        if (hours < 0)
        {
          throw runtime_error("Invalid data!");
        }

        courses.push_back(make_unique<Course>(name, code, credits, hours));

        cout << "Course added.\n";
        History::addRecord("Admin added course.", adminHistoryFile);
      }
      else if (choice == 4)
      {
        string name, teacher, group, day, time, room;
        bool online;

        cout << "Lesson name: ";
        cin >> name;

        cout << "Teacher name: ";
        cin >> teacher;

        cout << "Group: ";
        cin >> group;

        cout << "Day: ";
        cin >> day;

        cout << "Time: ";
        cin >> time;

        cout << "Room: ";
        cin >> room;

        cout << "Is it an online lesson(Yes=1/No=0): ";
        cin >> online;

        schedule.push_back(make_unique<Lesson>(name, teacher, group, day, time, room, online));

        cout << "Lesson added.\n";
        History::addRecord("Admin added a lesson to schedule.", adminHistoryFile);
      }
      else if (choice == 5)
      {
        for (auto &s : students)
        {
          s->showInfo();
          cout << endl;
          History::addRecord("Admin viewed students.", adminHistoryFile);
        }
      }
      else if (choice == 6)
      {
        for (auto &t : teachers)
        {
          t->showInfo();
          cout << endl;
          History::addRecord("Admin viewed teachers.", adminHistoryFile);
        }
      }
      else if (choice == 7)
      {
        for (auto &c : courses)
        {
          c->showInfo();
          cout << endl;
          History::addRecord("Admin viewed courses.", adminHistoryFile);
        }
      }
      else if (choice == 8)
      {
        for (auto &s : schedule)
        {
          s->showInfo();
          cout << endl;
          History::addRecord("Admin viewed schedule.", adminHistoryFile);
        }
      }
      else if (choice == 9)
      {
        for (int i = 0; i < students.size(); i++)
        {
          cout << i << ". ";
          cout << students[i]->GetName() << endl;
        }

        int index;
        cout << "Enter index to delete: ";
        cin >> index;

        if (index < 0 || index >= students.size())
        {
          throw runtime_error("Invalid data!");
        }

        students.erase(students.begin() + index);

        cout << "Student deleted.\n";
        History::addRecord("Admin deleted student.", adminHistoryFile);
      }
      else if (choice == 10)
      {
        for (int i = 0; i < teachers.size(); i++)
        {
          cout << i << ". ";
          cout << teachers[i]->GetName() << endl;
        }

        int index;
        cout << "Enter index to delete: ";
        cin >> index;

        if (index < 0 || index >= teachers.size())
        {
          throw runtime_error("Invalid data!");
        }

        teachers.erase(teachers.begin() + index);

        cout << "Teacher deleted.\n";
        History::addRecord("Admin deleted teacher.", adminHistoryFile);
      }
      else if (choice == 11)
      {
        for (int i = 0; i < courses.size(); i++)
        {
          cout << i << ". ";
          cout << courses[i]->GetName() << endl;
        }

        int index;
        cout << "Enter index to delete: ";
        cin >> index;

        if (index < 0 || index >= courses.size())
        {
          throw runtime_error("Invalid data!");
        }

        courses.erase(courses.begin() + index);

        cout << "Course deleted.\n";
        History::addRecord("Admin deleted course.", adminHistoryFile);
      }
      else if (choice == 12)
      {
        for (int i = 0; i < schedule.size(); i++)
        {
          cout << i << ". ";
          cout << schedule[i]->GetName() << endl;
        }

        int index;
        cout << "Enter index to delete: ";
        cin >> index;

        if (index < 0 || index >= schedule.size())
        {
          throw runtime_error("Invalid data!");
        }

        schedule.erase(schedule.begin() + index);

        cout << "Lesson deleted.\n";
        History::addRecord("Admin deleted lesson.", adminHistoryFile);
      }
      else if (choice == 13)
      {
        FileManager::saveStudents(students);
        FileManager::saveTeachers(teachers);
        FileManager::saveCourses(courses);
        FileManager::saveSchedule(schedule);
        cout << "Data saved!" << endl;
      }
      else if (choice == 14)
      {
        vector<string> history = History::loadHistory(adminHistoryFile);

        for (const auto &line : history)
        {
          cout << line << endl;
        }
      }
      else if (choice == 15)
      {
        History::clearHistory(adminHistoryFile);
        cout << "Admin history cleared.\n";
      }
      else if (choice == 16)
      {
        for (auto &s : students)
        {
          cout << s->GetName() << ": ";
          s->isAdult();
        }

        History::addRecord("Admin checked students' age.", adminHistoryFile);
      }
      else if (choice == 17)
      {
        for (auto &s : students)
        {
          cout << "ID: " << s->GetId() << "---Name: " << s->GetName() << endl;
        }

        History::addRecord("Admin viewed students' IDs.", adminHistoryFile);
      }
      else if (choice == 18)
      {
        cout << "Number of students: " << Student::GetAmount() << endl;

        History::addRecord("Admin viewed number of students.", adminHistoryFile);
      }
      else if (choice == 0)
      {
        break;
      }
    }
    catch (exception &e)
    {
      cout << "Error: " << e.what() << endl;
    }
  }
}

void UniversitySystem::userMenu()
{
  int choice;

  while (true)
  {
    cout << "\n---------- User Menu ----------\n";
    cout << "1. Show information about teachers\n";
    cout << "2. Show information about courses\n";
    cout << "3. Show schedule\n";
    cout << "4. View history\n";
    cout << "5. Delete history\n";
    cout << "0. Back\n";

    cin >> choice;

    if (choice == 1)
    {
      for (auto &t : teachers)
      {
        t->showInfo();
        cout << endl;
        History::addRecord("User viewed teachers.", userHistoryFile);
      }
    }
    else if (choice == 2)
    {
      for (auto &c : courses)
      {
        c->showInfo();
        cout << endl;
        History::addRecord("User viewed courses.", userHistoryFile);
      }
    }
    else if (choice == 3)
    {
      for (auto &s : schedule)
      {
        s->showInfo();
        cout << endl;
        History::addRecord("User viewed schedule.", userHistoryFile);
      }
    }
    else if (choice == 4)
    {
      vector<string> history = History::loadHistory(userHistoryFile);

      for (const auto &line : history)
      {
        cout << line << endl;
      }
    }
    else if (choice == 5)
    {
      History::clearHistory(userHistoryFile);
      cout << "User history cleared.\n";
    }
    else if (choice == 0)
    {
      break;
    }
  }
}