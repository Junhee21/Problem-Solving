#include <iostream>
#include <vector>
using namespace std;

int n, k;
const int NUM = 1000000000;
vector<vector<int>> dp;

int getSum(int num, int target) {
  if (dp[num][target] != 0)
    return dp[num][target];
  if (num == 1)
    return 1;
  long long sum = 0;
  for (int i = 0; i <= target; i++) {
    sum += getSum(num - 1, i);
  }
  dp[num][target] = sum % NUM;
  return dp[num][target];
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;

  dp.assign(k + 1, vector<int>(n + 1, 0));
  cout << getSum(k, n);

  return 0;
}