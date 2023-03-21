#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> arr;
vector<int> cnt;
vector<int> odcs;
stack<int> s;

int main(void) {
  int n;
  cin >> n;
  arr.assign(n, 0);
  cnt.assign(1000001, 0);
  odcs.assign(n, -1);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = num;
    cnt[num]++;
  }

  for (int i = 0; i < n; i++) {
    while (!s.empty() && (cnt[arr[s.top()]] < cnt[arr[i]])) {
      odcs[s.top()] = arr[i];
      s.pop();
    }
    s.push(i);
  }

  for (int i = 0; i < n; i++) {
    cout << odcs[i] << " ";
  }
  return 0;
}