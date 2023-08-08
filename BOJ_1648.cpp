#include <iostream>
#include <vector>
using namespace std;

const int MOD = 9901;
int n, m;
vector<vector<int>> dp;

int search_dp(int idx, int bit) {
  if (idx == n * m) {
    if (bit == 0)
      return 1;
    else
      return 0;
  }
  if (dp[idx][bit] != -1)
    return dp[idx][bit];
  int res;
  if (bit & 1) {
    res = search_dp(idx + 1, bit >> 1);
  } else {
    int new_bit = bit;
    new_bit |= (1 << m);
    res = search_dp(idx + 1, new_bit >> 1);
    if (idx % m < m - 1 && !(bit & 2)) {
      res += search_dp(idx + 1, (bit >> 1) | 1);
    }
  }
  res %= MOD;
  dp[idx][bit] = res;
  return res;
}

int main(void) {
  cin >> n >> m;
  if ((n * m) % 2 == 1)
    cout << 0;
  else {
    dp.assign(n * m, vector<int>(1 << m, -1));
    cout << search_dp(0, 0);
  }
  return 0;
}