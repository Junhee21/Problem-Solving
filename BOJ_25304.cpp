#include <iostream>
using namespace std;

int main(void) {
  int totalSum, totalNum;
  cin >> totalSum >> totalNum;
  for (int i = 0; i < totalNum; i++) {
    int price, num;
    cin >> price >> num;
    totalSum -= price * num;
  }
  if (totalSum == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}