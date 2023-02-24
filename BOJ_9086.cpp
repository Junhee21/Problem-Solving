#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    cout << s.front() << s.back() << "\n";
  }
  return 0;
}