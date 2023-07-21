#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> arr(n, "");
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n > 32) {
      cout << 0 << "\n";
      continue;
    }
    int result = 987654321;
    for (int i = 0; i < n - 2; i++) {
      for (int j = i + 1; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
          int temp = 0;
          if (arr[i][0] != arr[j][0] || arr[j][0] != arr[k][0])
            temp += 2;
          if (arr[i][1] != arr[j][1] || arr[j][1] != arr[k][1])
            temp += 2;
          if (arr[i][2] != arr[j][2] || arr[j][2] != arr[k][2])
            temp += 2;
          if (arr[i][3] != arr[j][3] || arr[j][3] != arr[k][3])
            temp += 2;
          if (result > temp)
            result = temp;
        }
      }
    }
    cout << result << "\n";
  }
  return 0;
}