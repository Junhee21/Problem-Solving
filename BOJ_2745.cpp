#include <iostream>
using namespace std;

int main(void) {
  string str;
  int n;
  cin >> str >> n;
  int sum = 0;
  int cnt = 1;
  for (int i = 0; i < str.length(); i++) {
    int num = str[str.length() - i - 1];
    if (num >= 'A') {
      num = num - 'A' + 10;
    } else {
      num = num - '0';
    }
    sum += cnt * num;
    cnt *= n;
  }
  cout << sum;
  return 0;
}