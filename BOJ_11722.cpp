#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> arr;

int main(void) {
  int answer = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    arr.push_back(a);
    dp.push_back(1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] < arr[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        answer = dp[i] > answer ? dp[i] : answer;
      }
    }
  }
  cout << answer;
  return 0;
}