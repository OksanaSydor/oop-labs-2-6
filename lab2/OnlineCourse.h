#ifndef ONLINECOURSE_H
#define ONLINECOURSE_H

#include "Course.h"

class OnlineCourse : public Course
{
public:
  OnlineCourse(string name = "Unknown");

  void showInfo();
};

#endif