#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

vector<long long> factorial;

long long get_pow(long long num, int cnt) {
  if (cnt == 0)
    return 1;
  long long res = get_pow(num, cnt / 2);
  if (cnt % 2 == 1)
    return (((res * res) % MOD) * num) % MOD;
  else
    return (res * res) % MOD;
}

long long mod_inv(long long num) { return get_pow(num, MOD - 2) % MOD; }

int main(void) {
  long long n, k;
  cin >> n >> k;

  factorial.resize(n + 2);
  factorial[0] = 1;
  for (int i = 1; i <= n + 1; i++)
    factorial[i] = (factorial[i - 1] * i) % MOD;

  long long k_pow = 1;
  for (int i = 0; i < n / 2; i++)
    k_pow = (k_pow * k) % MOD;

  long long result = 0;
  for (long long i = n / 2; i <= n; i++) {
    long long j = n - i;
    long long temp = ((i - j + 1) * factorial[n]) % MOD;
    temp = (temp * mod_inv((factorial[i + 1] * factorial[j]) % MOD)) % MOD;
    temp = (temp * k_pow) % MOD;
    result = (result + temp) % MOD;
    k_pow = (k_pow * k) % MOD;
  }
  cout << result;
  return 0;
}