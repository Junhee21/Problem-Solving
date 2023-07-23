#include <iostream>
#include <string>
#include <vector>
using namespace std;

using matrix = vector<vector<long long>>;
const int MOD = 1000003;
int n, s, e, t;
matrix edges;

matrix operator*(matrix &a, matrix &b) {
  int len = n * 5;
  matrix result(len, vector<long long>(len, 0));
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      long long sum = 0;
      for (int k = 0; k < len; k++) {
        sum += a[i][k] * b[k][j];
      }
      result[i][j] = sum % MOD;
    }
  }
  return result;
}

int main(void) {
  cin >> n >> s >> e >> t;
  edges.assign(n * 5, vector<long long>(n * 5, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      edges[i * 5 + j][i * 5 + j + 1] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      if (str[j] == '0')
        continue;
      edges[i * 5 + str[j] - '0' - 1][j * 5] = 1;
    }
  }

  matrix result(n * 5, vector<long long>(n * 5, 0));
  for (int i = 0; i < n * 5; i++) {
    result[i][i] = 1;
  }

  while (t > 0) {
    if (t % 2 == 1) {
      result = result * edges;
    }
    t /= 2;
    edges = edges * edges;
  }

  cout << result[(s - 1) * 5][(e - 1) * 5];

  return 0;
}