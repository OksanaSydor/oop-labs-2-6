#include "OnlineCourse.h"
#include <iostream>

using namespace std;

OnlineCourse::OnlineCourse(string name) : Course(name) {}

void OnlineCourse::showInfo()
{
  cout << "This is an online course." << endl;
}