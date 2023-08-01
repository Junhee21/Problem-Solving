#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Line {
  int s, e;
};

vector<Line> lines;
priority_queue<int> pq;

bool compare(Line a, Line b) { return a.e == b.e ? a.s < b.s : a.e < b.e; }

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    lines.push_back({a, b});
  }
  int d;
  cin >> d;
  sort(lines.begin(), lines.end(), compare);
  int answer = 0;
  for (auto iter = lines.begin(); iter != lines.end(); iter++) {
    while (!pq.empty()) {
      if (-pq.top() < (*iter).e - d) {
        pq.pop();
      } else {
        break;
      }
    }
    if ((*iter).s >= (*iter).e - d) {
      pq.push(-(*iter).s);
      if (pq.size() > answer) {
        answer = pq.size();
      }
    }
  }
  cout << answer;
  return 0;
}