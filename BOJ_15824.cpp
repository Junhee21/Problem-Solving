#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr;
vector<long long> cumsum;
const int MOD = 1000000007;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 0;
    return 0;
  }
  arr.resize(n);
  cumsum.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  cumsum[0] = arr[0];
  for (int i = 1; i < n; i++) {
    cumsum[i] = (cumsum[i - 1] + arr[i]) % MOD;
  }
  long long answer = 0;
  long long comb_sum = 1;
  for (int i = 0; i < n - 1; i++) {
    answer += comb_sum * (cumsum[n - 1] - cumsum[i] - cumsum[n - 1 - i - 1]);
    answer %= MOD;
    comb_sum = comb_sum * 2 % MOD;
  }
  if (answer < 0) {
    answer += MOD;
  }
  cout << answer;
  return 0;
}