#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<string> classroom;
vector<vector<int>> dp;

int solve_dp(int r, int c) {
  if (c < 0)
    return 0;
  if (dp[r][c] != -1)
    return dp[r][c];
  for (int i = 0; i < classroom.size(); i++) {
    if ((int)pow(2, i) & r && classroom[i][c] == 'x') {
      dp[r][c] = 0;
      return 0;
    }
  }
  vector<int> arr;
  for (int i = 0; i < (int)pow(2, n); i++) {
    if (i & r)
      continue;
    int left_shift = r << 1;
    if (i & left_shift)
      continue;
    int right_shift = r >> 1;
    if (i & right_shift)
      continue;
    arr.push_back(solve_dp(i, c - 1));
  }
  int cnt = 0;
  int temp = r;
  while (temp) {
    temp = temp & (temp - 1);
    cnt++;
  }
  if (arr.size() > 0) {
    cnt += *max_element(arr.begin(), arr.end());
  }
  dp[r][c] = cnt;
  return dp[r][c];
}

int main(void) {
  int tc;
  cin >> tc;
  vector<int> arr;
  while (tc--) {
    cin >> n >> m;
    classroom.assign(n, "");
    for (int i = 0; i < n; i++) {
      cin >> classroom[i];
    }
    dp.assign((int)pow(2, n), vector<int>(m, -1));
    vector<int> arr;
    for (int i = 0; i < (int)pow(2, n); i++) {
      arr.push_back(solve_dp(i, m - 1));
    }
    cout << *max_element(arr.begin(), arr.end()) << "\n";
  }
  return 0;
}