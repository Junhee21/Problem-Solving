#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (i >= s.length() - 1 - i)
      break;
    if (s[i] != s[s.length() - 1 - i]) {
      cout << 0;
      return 0;
    }
  }
  cout << 1;
  return 0;
}