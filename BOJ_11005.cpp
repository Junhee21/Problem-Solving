#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;
  stack<char> s;
  while (a > 0) {
    int num = a % b;
    if (num > 9) {
      s.push('A' + num - 10);
    } else {
      s.push('0' + num);
    }
    a /= b;
  }
  string str = "";
  while (!s.empty()) {
    str += s.top();
    s.pop();
  }
  cout << str;
  return 0;
}