#include <iostream>
using namespace std;

const long long QUOTIENT = 1000000009;
long long dp[1000001];

void init(void) {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= 1000000; i++) {
    long long temp = dp[i - 1] + dp[i - 2] + dp[i - 3];
    dp[i] = temp % QUOTIENT;
  }
}

int main(void) {
  int N;
  cin >> N;
  init();
  while (N--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}