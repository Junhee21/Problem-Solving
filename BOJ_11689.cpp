#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  long long n;
  cin >> n;
  vector<pair<long long, int>> arr;
  for (long long i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      cnt++;
      n /= i;
    }
    if (cnt != 0) {
      arr.push_back({i, cnt});
    }
  }
  if (n != 1) {
    arr.push_back({n, 1});
  }
  long long answer = 1;
  for (auto iter = arr.begin(); iter != arr.end(); iter++) {
    answer *=
        (long long)pow((*iter).first, (*iter).second - 1) * ((*iter).first - 1);
  }
  cout << answer;
  return 0;
}