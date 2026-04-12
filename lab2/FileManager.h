#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <memory>
#include <fstream>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Lesson.h"

using namespace std;

class FileManager
{
public:
  static void saveStudents(const vector<unique_ptr<Student>> &students);
  static void loadStudents(vector<unique_ptr<Student>> &students);

  static void saveTeachers(const vector<unique_ptr<Teacher>> &teachers);
  static void loadTeachers(vector<unique_ptr<Teacher>> &teachers);

  static void saveCourses(const vector<unique_ptr<Course>> &courses);
  static void loadCourses(vector<unique_ptr<Course>> &courses);

  static void saveSchedule(const vector<unique_ptr<Lesson>> &schedule);
  static void loadSchedule(vector<unique_ptr<Lesson>> &schedule);
};

#endif