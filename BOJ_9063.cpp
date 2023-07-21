#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int min_r = 10001;
  int max_r = -10001;
  int min_c = 10001;
  int max_c = -10001;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    if (r < min_r)
      min_r = r;
    if (r > max_r)
      max_r = r;
    if (c < min_c)
      min_c = c;
    if (c > max_c)
      max_c = c;
  }
  cout << (max_r - min_r) * (max_c - min_c);
  return 0;
}