#include "FileManager.h"

void FileManager::saveStudents(const vector<unique_ptr<Student>> &students)
{
  try
  {
    ofstream out("students.txt");
    if (!out)
    {
      throw runtime_error("Can not open file.");
    }
    for (const auto &s : students)
    {
      out << s->GetName() << " "
          << s->GetAge() << " "
          << s->GetFaculty() << endl;
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::loadStudents(vector<unique_ptr<Student>> &students)
{
  try
  {
    ifstream in("students.txt");
    if (!in)
    {
      throw runtime_error("Can not open file.");
    }

    string name, faculty;
    int age;

    while (in >> name >> age >> faculty)
    {
      students.push_back(make_unique<Student>(name, age, faculty));
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::saveTeachers(const vector<unique_ptr<Teacher>> &teachers)
{
  try
  {
    ofstream out("teachers.txt");
    if (!out)
    {
      throw runtime_error("Can not open file.");
    }

    for (const auto &t : teachers)
    {
      out << t->GetName() << " "
          << t->GetAge() << " "
          << t->GetDepartment() << " "
          << t->GetExperienceYears() << endl;
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::loadTeachers(vector<unique_ptr<Teacher>> &teachers)
{
  try
  {
    ifstream in("teachers.txt");
    if (!in)
    {
      throw runtime_error("Can not open file.");
    }

    string name, department;
    int age, experience;

    while (in >> name >> age >> department >> experience)
    {
      teachers.push_back(make_unique<Teacher>(name, age, department, experience));
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::saveCourses(const vector<unique_ptr<Course>> &courses)
{
  try
  {
    ofstream out("courses.txt");
    if (!out)
    {
      throw runtime_error("Can not open file.");
    }

    for (const auto &c : courses)
    {
      out << c->GetName() << " "
          << c->GetCode() << " "
          << c->GetCredits() << " "
          << c->GetHours() << endl;
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::loadCourses(vector<unique_ptr<Course>> &courses)
{
  try
  {
    ifstream in("courses.txt");
    if (!in)
    {
      throw runtime_error("Can not open file.");
    }

    string name, code;
    int credits, hours;

    while (in >> name >> code >> credits >> hours)
    {
      courses.push_back(make_unique<Course>(name, code, credits, hours));
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::saveSchedule(const vector<unique_ptr<Lesson>> &schedule)
{
  try
  {
    ofstream out("schedule.txt");
    if (!out)
    {
      throw runtime_error("Can not open file.");
    }

    for (const auto &s : schedule)
    {
      out << *s << endl;
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void FileManager::loadSchedule(vector<unique_ptr<Lesson>> &schedule)
{
  try
  {
    ifstream in("schedule.txt");
    if (!in)
    {
      throw runtime_error("Can not open file.");
    }

    Lesson temp;

    while (in >> temp)
    {
      schedule.push_back(make_unique<Lesson>(temp));
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}