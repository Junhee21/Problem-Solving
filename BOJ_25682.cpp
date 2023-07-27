#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> prefix_sum_black;
vector<vector<int>> prefix_sum_white;

int main(void) {
  cin >> n >> m >> k;

  prefix_sum_black.assign(n + 1, vector<int>(m + 1, 0));
  prefix_sum_white.assign(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      prefix_sum_black[i + 1][j + 1] = prefix_sum_black[i][j + 1] +
                                       prefix_sum_black[i + 1][j] -
                                       prefix_sum_black[i][j];
      prefix_sum_white[i + 1][j + 1] = prefix_sum_white[i][j + 1] +
                                       prefix_sum_white[i + 1][j] -
                                       prefix_sum_white[i][j];
      if (str[j] == 'B') {
        if ((i + j) % 2 == 0) {
          prefix_sum_white[i + 1][j + 1]++;
        } else {
          prefix_sum_black[i + 1][j + 1]++;
        }
      } else {
        if ((i + j) % 2 == 0) {
          prefix_sum_black[i + 1][j + 1]++;
        } else {
          prefix_sum_white[i + 1][j + 1]++;
        }
      }
    }
  }

  int result = 987654321;
  for (int i = 1 + k - 1; i <= n; i++) {
    for (int j = 1 + k - 1; j <= m; j++) {
      int prefix_sum = prefix_sum_black[i][j] - prefix_sum_black[i][j - k] -
                       prefix_sum_black[i - k][j] +
                       prefix_sum_black[i - k][j - k];
      if (prefix_sum < result)
        result = prefix_sum;
    }
  }
  for (int i = 1 + k - 1; i <= n; i++) {
    for (int j = 1 + k - 1; j <= m; j++) {
      int prefix_sum = prefix_sum_white[i][j] - prefix_sum_white[i][j - k] -
                       prefix_sum_white[i - k][j] +
                       prefix_sum_white[i - k][j - k];
      if (prefix_sum < result)
        result = prefix_sum;
    }
  }
  cout << result;
  return 0;
}