#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> lines;

bool compare(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

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
  sort(lines.begin(), lines.end(), compare);
  int res = 0;
  int s = -2000000000, e = -2000000000;
  for (int i = 0; i < n; i++) {
    if (lines[i].first > e) {
      res += (e - s);
      s = lines[i].first;
    }
    if (lines[i].second > e) {
      e = lines[i].second;
    }
  }
  cout << res + e - s;
  return 0;
}