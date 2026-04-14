#ifndef UNIVERSITYSYSTEM_H
#define UNIVERSITYSYSTEM_H

#include <vector>
#include <memory>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Lesson.h"
#include "FileManager.h"
#include "History.h"

using namespace std;

class UniversitySystem
{
private:
  vector<unique_ptr<Student>> students;
  vector<unique_ptr<Teacher>> teachers;
  vector<unique_ptr<Course>> courses;
  vector<unique_ptr<Lesson>> schedule;

  string adminPassword = "8888";
  
  const string adminHistoryFile = "admin_history.txt";
  const string userHistoryFile = "user_history.txt";

  void adminMenu();
  void userMenu();

public:
  void launch();
};

#endif