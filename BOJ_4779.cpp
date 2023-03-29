#include <cmath>
#include <iostream>
using namespace std;

void printBlank(int num) {
  for (int i = 0; i < (int)pow(3, num); i++) {
    cout << " ";
  }
}

void print(int num) {
  if (num == 0) {
    cout << "-";
  } else {
    print(num - 1);
    printBlank(num - 1);
    print(num - 1);
  }
}

int main(void) {
  int n;
  while (cin >> n) {
    print(n);
    cout << "\n";
  }
  return 0;
}