#include <iostream>
using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 1; i <= a; i++) {
    if (a % i == 0)
      cnt++;
    if (cnt == b) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}