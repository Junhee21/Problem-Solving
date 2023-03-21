#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<long long> box;
stack<int> s;

int main(void) {
  int n;
  cin >> n;
  box.assign(n + 2, 0);
  for (int i = 1; i <= n; i++) {
    cin >> box[i];
  }

  long long histogramArea = 0;
  for (int i = 0; i <= n + 1; i++) {
    while (!s.empty() && (box[s.top()] > box[i])) {
      long long height = box[s.top()];
      s.pop();
      int front = s.top();
      histogramArea = max(histogramArea, height * (i - front - 1));
    }
    s.push(i);
  }

  cout << histogramArea;
  return 0;
}