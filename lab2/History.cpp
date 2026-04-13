#include "History.h"
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void History::addRecord(const string &info, const string &fileName)
{
  ofstream out(fileName, ios::app);
  if (!out)
    return;

  out << info << endl;
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