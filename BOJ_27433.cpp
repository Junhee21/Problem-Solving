#include <iostream>
using namespace std;

long long get_factorial(int n) {
  if (n == 0)
    return 1;
  return n * get_factorial(n - 1);
}

int main(void) {
  int n;
  cin >> n;
  cout << get_factorial(n);
  return 0;
}