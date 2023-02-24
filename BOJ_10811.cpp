#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> arr(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    arr[i] = i;
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    for (int i = 0; a + i < b - i; i++) {
      int temp = arr[a + i];
      arr[a + i] = arr[b - i];
      arr[b - i] = temp;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}