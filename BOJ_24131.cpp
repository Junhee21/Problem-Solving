#include <iostream>
using namespace std;

int main(void) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a > c) {
    cout << 0;
  } else if (a == c) {
    if (b <= 0) {
      cout << 1;
    } else {
      cout << 0;
    }
  } else {
    if (a * d + b > c * d) {
      cout << 0;
    } else {
      cout << 1;
    }
  }
  return 0;
}