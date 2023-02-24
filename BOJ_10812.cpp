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
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> tempArr(b - a + 1, 0);
    for (int i = 0; i < b - c + 1; i++) {
      tempArr[i] = arr[c + i];
    }
    for (int i = 0; i < c - a; i++) {
      tempArr[i + b - c + 1] = arr[a + i];
    }
    for (int i = 0; i < b - a + 1; i++) {
      arr[a + i] = tempArr[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}