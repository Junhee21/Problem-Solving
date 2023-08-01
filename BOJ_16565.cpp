#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> comb(49, vector<long long>(49, 0));
const int MOD = 10007;

long long get_comb(int n, int m) {
  if (comb[n][m] != 0)
    return comb[n][m];
  if (n == m || m == 0) {
    comb[n][m] = 1;
    return 1;
  }
  comb[n][m] = (get_comb(n - 1, m) + get_comb(n - 1, m - 1)) % MOD;
  return comb[n][m];
}

int main(void) {
  int n;
  cin >> n;
  long long answer = 0;
  long long dir = 1;

  for (int i = 1; i * 4 <= n; i++) {
    answer += dir * get_comb(13, i) * get_comb(52 - i * 4, n - i * 4);
    answer %= MOD;
    dir *= -1;
  }
  if (answer < 0) {
    answer += MOD;
  }
  cout << answer;
  return 0;
}