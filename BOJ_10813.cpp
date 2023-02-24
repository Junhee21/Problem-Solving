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
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}