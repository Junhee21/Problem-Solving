#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  while (n--) {
    long long num;
    cin >> num;
    while (true) {
      if (num == 0 || num == 1) {
        cout << 2 << "\n";
        break;
      }
      bool isPrime = true;
      for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        cout << num << "\n";
        break;
      }
      num++;
    }
  }
  return 0;
}