#include <iostream>
using namespace std;

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  if (b > a && b > c) {
    int temp = a;
    a = b;
    b = temp;
  } else if (c > a && c > b) {
    int temp = a;
    a = c;
    c = temp;
  }
  if (a < b + c) {
    cout << a + b + c;
  } else {
    cout << 2 * (b + c) - 1;
  }
  return 0;
}