#include <iostream>
using namespace std;

int main(void) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int e, f;
  f = b * d;
  e = a * d + b * c;

  int i = 2;
  while (true) {
    if (e % i == 0 && f % i == 0) {
      e /= i;
      f /= i;
    } else {
      if (i * i > e || i * i > f)
        break;
      i++;
    }
  }
  cout << e << " " << f;
  return 0;
}