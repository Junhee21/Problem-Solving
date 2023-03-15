#include <iostream>
using namespace std;

long long getGcd(long long a, long long b) {
  while (true) {
    if (a >= b) {
      if (a % b == 0)
        return b;
      a = a % b;
    } else {
      if (b % a == 0)
        return a;
      b = b % a;
    }
  }
}

int main(void) {
  long long a, b;
  cin >> a >> b;
  cout << a * b / getGcd(a, b);
  return 0;
}