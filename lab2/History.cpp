#include "History.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void History::addRecord(const string &action, const string &fileName)
{
  ofstream out(fileName, ios::app);
  if (!out)
    return;
}

vector<string> History::loadHistory(const string &fileName)
{
  vector<string> history;
  ifstream in(fileName);
  string line;

  while (getline(in, line))
  {
    history.push_back(line);
  }

  return history;
}