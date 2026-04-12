#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <vector>
using namespace std;

class History
{
public:
  static void addRecord(const string &action, const string &fileName = "history.txt");
  static vector<string> loadHistory(const string &fileName = "history.txt");
};

#endif