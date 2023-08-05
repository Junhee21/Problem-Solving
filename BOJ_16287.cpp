#include <iostream>
#include <vector>
using namespace std;

vector<bool> checked(400001, false);
vector<int> arr;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int w, n;
  cin >> w >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (w - arr[i] - arr[j] >= 0 && w - arr[i] - arr[j] <= 400000 &&
          checked[w - arr[i] - arr[j]]) {
        cout << "YES";
        return 0;
      }
    }
    for (int j = i - 1; j >= 0; j--) {
      checked[arr[i] + arr[j]] = true;
    }
  }
  cout << "NO";
  return 0;
}