#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1, 0);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = a; i <= b; i++) {
      arr[i] = c;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}