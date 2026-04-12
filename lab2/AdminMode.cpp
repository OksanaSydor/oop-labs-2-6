#include "AdminMode.h"

AdminMode::AdminMode(string password) : adminPassword(password)
{
}

bool AdminMode::checkPassword(const string &input) const
{
  return input == adminPassword;
}

void AdminMode::SetPassword(const string &newPassword)
{
  adminPassword = newPassword;
}