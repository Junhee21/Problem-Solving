#include <iostream>
using namespace std;

int main(void) {
  while (true) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0)
      return 0;
    if (b > a && b > c) {
      int temp = a;
      a = b;
      b = temp;
    } else if (c > a && c > b) {
      int temp = a;
      a = c;
      c = temp;
    }
    if (c > b) {
      int temp = b;
      b = c;
      c = temp;
    }
    if (a >= b + c) {
      cout << "Invalid\n";
    } else if (a == b && b == c) {
      cout << "Equilateral\n";
    } else if (a == b || b == c || a == c) {
      cout << "Isosceles\n";
    } else {
      cout << "Scalene\n";
    }
  }
}