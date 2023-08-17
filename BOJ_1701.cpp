#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  string str;
  cin >> str;
  int res = 0;

  for (int i = 0; i < str.size() - 1; i++) {
    vector<int> pi(str.size() - i, 0);
    int k = 0;
    for (int j = 1; j < str.size() - i; j++) {
      while (k > 0 && str[j + i] != str[k + i])
        k = pi[k - 1];
      if (str[j + i] == str[k + i]) {
        pi[j] = ++k;
        res = k > res ? k : res;
      }
    }
  }
  cout << res;
  return 0;
}
