#include "FileManager.h"

void FileManager::saveStudents(const vector<unique_ptr<Student>> &students)
{
  ofstream out("students.txt");

  for (const auto &s : students)
  {
    out << s->GetName() << " "
        << s->GetAge() << " "
        << s->GetFaculty() << endl;
  }
}

void FileManager::loadStudents(vector<unique_ptr<Student>> &students)
{
  ifstream in("students.txt");

  string name, faculty;
  int age;

  while (in >> name >> age >> faculty)
  {
    students.push_back(make_unique<Student>(name, age, faculty));
  }
}

void FileManager::saveTeachers(const vector<unique_ptr<Teacher>> &teachers)
{
  ofstream out("teachers.txt");

  for (const auto &t : teachers)
  {
    out << t->GetName() << " "
        << t->GetAge() << " "
        << t->GetDepartment() << " "
        << t->GetExperienceYears() << endl;
  }
}

void FileManager::loadTeachers(vector<unique_ptr<Teacher>> &teachers)
{
  ifstream in("teachers.txt");

  string name, department;
  int age, experience;

  while (in >> name >> age >> department >> experience)
  {
    teachers.push_back(make_unique<Teacher>(name, age, department, experience));
  }
}

void FileManager::saveCourses(const vector<unique_ptr<Course>> &courses)
{
  ofstream out("courses.txt");

  for (const auto &c : courses)
  {
    out << c->GetName() << " "
        << c->GetCode() << " "
        << c->GetCredits() << " "
        << c->GetHours() << endl;
  }
}

void FileManager::loadCourses(vector<unique_ptr<Course>> &courses)
{
  ifstream in("courses.txt");

  string name, code;
  int credits, hours;

  while (in >> name >> code >> credits >> hours)
  {
    courses.push_back(make_unique<Course>(name, code, credits, hours));
  }
}

void FileManager::saveSchedule(const vector<unique_ptr<Lesson>> &schedule)
{
  ofstream out("schedule.txt");

  for (const auto &s : schedule)
  {
    out << *s << endl;
  }
}

void FileManager::loadSchedule(vector<unique_ptr<Lesson>> &schedule)
{
  ifstream in("schedule.txt");

  Lesson temp;

  while (in >> temp)
  {
    schedule.push_back(make_unique<Lesson>(temp));
  }
}