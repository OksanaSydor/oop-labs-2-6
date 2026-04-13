#include "History.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void History::addRecord(const string &info, const string &fileName)
{
  try
  {
    ofstream out(fileName, ios::app);
    if (!out)
    {
      throw runtime_error("Can not open file.");
    }

    out << info << endl;
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
}

void History::clearHistory(const string &fileName)
{
  try
  {
    ofstream out(fileName);

    if (!out)
    {
      throw runtime_error("Can not clear history file.");
    }
  }
  catch (exception &e)
  {
    cout << "Error: " << e.what() << endl;
  }
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