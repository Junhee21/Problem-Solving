#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> result;
queue<pair<int, int>> q;

int main(void) {
  cin >> n >> m;
  arr.assign(n, vector<int>(m, 0));
  result.assign(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) {
        result[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 2) {
        result[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 4; i++) {
      int r = node.first + dir[i].first;
      int c = node.second + dir[i].second;
      if (r < 0 || r >= n || c < 0 || c >= m)
        continue;
      if (arr[r][c] == 0)
        continue;
      if (result[r][c] == -1) {
        result[r][c] = result[node.first][node.second] + 1;
        q.push({r, c});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}