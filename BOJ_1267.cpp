#include <iostream>
using namespace std;

int main(void) {
  int cnt;
  cin >> cnt;
  int a = 0, b = 0;
  for (int i = 0; i < cnt; i++) {
    int n;
    cin >> n;
    a += 10 * (n / 30 + 1);
    b += 15 * (n / 60 + 1);
  }
  if (a < b) {
    cout << "Y " << a;
  } else if (a == b) {
    cout << "Y M " << a;
  } else {
    cout << "M " << b;
  }
  return 0;
}