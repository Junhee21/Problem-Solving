#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1000000007;

long long matrix_pow(long long n) {
  vector<vector<long long>> matrix = {{4, -1}, {1, 0}};
  vector<long long> res = {3, 1};
  while (true) {
    if (n % 2 == 1) {
      vector<long long> temp = {MOD, MOD};
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          temp[i] += matrix[i][j] * res[j];
          temp[i] %= MOD;
        }
      }
      res = temp;
    }
    if (n == 1)
      break;
    n /= 2;
    vector<vector<long long>> temp = {{MOD, MOD}, {MOD, MOD}};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          temp[i][j] += matrix[i][k] * matrix[k][j];
          temp[i][j] %= MOD;
        }
      }
    }
    matrix = temp;
  }
  return res[0];
}

int main(void) {
  long long n;
  cin >> n;
  if (n % 2 == 1) {
    cout << 0;
  } else if (n == 2) {
    cout << 3;
  } else {
    n /= 2;
    n -= 1;
    cout << matrix_pow(n);
  }
  return 0;
}
