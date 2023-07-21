#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
  set<string> s;
  int n;
  cin >> n;
  while (n--) {
    string a, b;
    cin >> a >> b;
    if (b == "enter") {
      s.insert(a);
    } else {
      s.erase(a);
    }
  }
  for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
    cout << *iter << "\n";
  }
  return 0;
}