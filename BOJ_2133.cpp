#include <iostream>
#include <vector>
using namespace std;

vector<int> dp(31, 0);

long long solve(long long n) {
  if (dp[n] != 0)
    return dp[n];
  if (n % 2 == 1)
    return 0;
  long long sum = 3 * solve(n - 2);
  for (long long i = n - 4; i >= 0; i -= 2) {
    sum += solve(i) * 2;
  }
  dp[n] = sum;
  return sum;
}

int main(void) {
  long long n;
  cin >> n;
  dp[0] = 1;
  cout << solve(n);
  return 0;
}