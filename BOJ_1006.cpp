#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, w;
vector<vector<int>> arr;
vector<vector<int>> dp;

int search_dp(int r, int c) {
  if (c < 0)
    return 0;
  if (dp[r][c] != -1)
    return dp[r][c];

  if (r == 2) {
    dp[r][c] = min(search_dp(0, c) + 1, search_dp(1, c) + 1);
    if (arr[0][c] + arr[1][c] <= w) {
      dp[r][c] = min(dp[r][c], search_dp(2, c - 1) + 1);
    }
    if (c > 0 && arr[0][c - 1] + arr[0][c] <= w &&
        arr[1][c - 1] + arr[1][c] <= w) {
      dp[r][c] = min(dp[r][c], search_dp(2, c - 2) + 2);
    }
  } else {
    dp[r][c] = search_dp(2, c - 1) + 1;
    if (c > 0 && arr[r][c - 1] + arr[r][c] <= w) {
      dp[r][c] = min(dp[r][c], search_dp(1 - r, c - 1) + 1);
    }
  }
  return dp[r][c];
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> w;
    arr.assign(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    dp.assign(3, vector<int>(n, -1));
    int a = search_dp(2, n - 1);

    if (n == 1) {
      cout << a << '\n';
      continue;
    }

    int b = 987654321;
    if (arr[0][0] + arr[0][n - 1] <= w) {
      dp.assign(3, vector<int>(n, -1));
      dp[0][0] = 0;
      b = search_dp(1, n - 1) + 1;
    }
    int c = 987654321;
    if (arr[1][0] + arr[1][n - 1] <= w) {
      dp.assign(3, vector<int>(n, -1));
      dp[1][0] = 0;
      c = search_dp(0, n - 1) + 1;
    }
    int d = 987654321;
    if (arr[1][0] + arr[1][n - 1] <= w && arr[0][0] + arr[0][n - 1] <= w) {
      dp.assign(3, vector<int>(n, -1));
      dp[0][0] = 0;
      dp[1][0] = 0;
      dp[2][0] = 0;
      d = search_dp(2, n - 2) + 2;
    }

    cout << min({a, b, c, d}) << "\n";
  }

  return 0;
}