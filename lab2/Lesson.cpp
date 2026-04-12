#include "Lesson.h"
#include <string>
// #include <sstream>
// #include <vector>
// #include <stdexcept>

using namespace std;

Lesson::Lesson(string teacherName, string groupName, string dayOfWeek, string startTime, string room, bool online) : teacherName(teacherName), groupName(groupName), dayOfWeek(dayOfWeek), startTime(startTime), room(room), online(online)
{
}

string Lesson::GetTeacherName() const { return teacherName; }
string Lesson::GetGroupName() const { return groupName; }
string Lesson::GetDayOfWeek() const { return dayOfWeek; }
string Lesson::GetStartTime() const { return startTime; }
string Lesson::GetRoom() const { return room; }
bool Lesson::IsOnline() const { return online; }

void Lesson::showInfo() const
{
  cout << "Teacher: " << teacherName << endl;
  cout << "Group: " << groupName << endl;
  cout << "Day: " << dayOfWeek << endl;
  cout << "Time: " << startTime << endl;
  cout << "Room: " << room << endl;
  cout << "Format: " << (online ? "Online" : "Offline") << endl;
}

ostream &operator<<(ostream &os, const Lesson &lesson)
{
  os << lesson.teacherName << " "
     << lesson.groupName << " "
     << lesson.dayOfWeek << " "
     << lesson.startTime << " "
     << lesson.room << " "
     << lesson.online;

  return os;
}

istream &operator>>(istream &is, Lesson &lesson)
{
  is >> lesson.teacherName >> lesson.groupName >> lesson.dayOfWeek >> lesson.startTime >> lesson.room >> lesson.online;

  return is;
}