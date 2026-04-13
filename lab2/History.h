#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <vector>
using namespace std;

class History
{
public:
  static void addRecord(const string &info, const string &fileName);
  static void clearHistory(const string &fileName);
  static vector<string> loadHistory(const string &fileName);
};

#endif