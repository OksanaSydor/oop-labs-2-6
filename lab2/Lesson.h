#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <iostream>
using namespace std;

class Lesson
{
private:
  string name;
  string teacherName;
  string groupName;
  string dayOfWeek;
  string startTime;
  string room;
  bool online;

public:
  Lesson(string name = "Unknown", string teacherName = "Unknown", string groupName = "Unknown", string dayOfWeek = "Unknown", string startTime = "00:00", string room = "Unknown", bool online = false);

  string GetName() const;
  string GetTeacherName() const;
  string GetGroupName() const;
  string GetDayOfWeek() const;
  string GetStartTime() const;
  string GetRoom() const;
  bool IsOnline() const;

  void showInfo() const;
  friend ostream &operator<<(ostream &os, const Lesson &lesson);
  friend istream &operator>>(istream &is, Lesson &lesson);
};

#endif