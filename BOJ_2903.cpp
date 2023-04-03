#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int cnt = 2;
  while (n--) {
    cnt = 2 * cnt - 1;
  }
  cout << cnt * cnt;
  return 0;
}