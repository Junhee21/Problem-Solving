#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  vector<vector<char>> table;
  for (int i = 0; i < 5; i++) {
    string s;
    cin >> s;
    table.push_back(vector<char>(0));
    for (int j = 0; j < s.length(); j++) {
      table[i].push_back(s[j]);
    }
  }
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 5; j++) {
      if (i >= table[j].size())
        continue;
      cout << table[j][i];
    }
  }
  return 0;
}