// 22 / 3 / 4

#include <iostream>
using namespace std;

int main(void)
{
  int a, b, c;
  cin >> a >> b >> c;
  if ((a == b) && (b == c))
    cout << 10000 + a * 1000;
  else if ((a == b) || (a == c))
    cout << 1000 + a * 100;
  else if (b == c)
    cout << 1000 + b * 100;
  else if ((a > b) && (a > c))
    cout << a * 100;
  else if (b > c)
    cout << b * 100;
  else
    cout << c * 100;
  return 0;
}