#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  cout << arr[n - k];
  return 0;
}