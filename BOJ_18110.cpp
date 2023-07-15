#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int cnt;
  cin >> cnt;

  if (cnt == 0) {
    cout << 0;
    return 0;
  }

  vector<int> arr;
  for (int i = 0; i < cnt; i++) {
    int n;
    cin >> n;
    arr.push_back(n);
  }

  sort(arr.begin(), arr.end());
  int sum = 0;
  int pole = int(round(cnt * 0.15));

  for (int i = pole; i < cnt - pole; i++) {
    sum += arr[i];
  }
  cout << int(round(double(sum) / (cnt - pole * 2)));
  return 0;
}