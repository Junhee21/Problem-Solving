#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<string> arrs;
vector<vector<bool>> checked;
queue<pair<int, int>> q;

int main(void) {
  cin >> n >> m;
  arrs.assign(n, "");
  checked.assign(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    cin >> arrs[i];
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arrs[i][j] == 'I') {
        q.push({i, j});
        checked[i][j] = true;
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
      int r = node.first + dir[i].first;
      int c = node.second + dir[i].second;
      if (r < 0 || r >= n || c < 0 || c >= m)
        continue;
      if (checked[r][c])
        continue;
      if (arrs[r][c] == 'X')
        continue;
      checked[r][c] = true;
      q.push({r, c});
      if (arrs[r][c] == 'P')
        result++;
    }
  }
  if (result == 0)
    cout << "TT";
  else
    cout << result;
  return 0;
}