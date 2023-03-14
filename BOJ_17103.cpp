#include <iostream>
#include <vector>
using namespace std;

vector<bool> isPrime(1000001, true);

void initPrimeVector() {
  for (int i = 2; i <= 1000000; i++) {
    if (!isPrime[i])
      continue;
    for (int j = i * 2; j <= 1000000; j += i)
      isPrime[j] = false;
  }
}

int main(void) {
  int n;
  cin >> n;
  initPrimeVector();
  while (n--) {
    int num, cnt = 0;
    cin >> num;
    for (int i = 2; i * 2 <= num; i++) {
      if (isPrime[i] && isPrime[num - i])
        cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}