#include <iostream>
using namespace std;

int main(void) {
  int testCase;
  cin >> testCase;
  while (testCase--) {
    int num;
    cin >> num;
    cout << num / 25 << " ";
    num %= 25;
    cout << num / 10 << " ";
    num %= 10;
    cout << num / 5 << " ";
    num %= 5;
    cout << num << "\n";
  }
  return 0;
}