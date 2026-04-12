#ifndef ADMINMODE_H
#define ADMINMODE_H

#include <string>
using namespace std;

class AdminMode
{
private:
  string adminPassword;

public:
  AdminMode(string password = "admin888");

  bool checkPassword(const string &input) const;
  void SetPassword(const string &newPassword);
};

#endif