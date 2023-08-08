#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> board;
vector<vector<int>> dp;
vector<vector<bool>> visited;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Node {
  int r, c, cnt;
};

int dfs(int r, int c) {
  if (visited[r][c])
    return -1;
  if (dp[r][c] != 0)
    return dp[r][c];

  visited[r][c] = true;
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int new_r = r + dir[i].first * (board[r][c] - '0');
    int new_c = c + dir[i].second * (board[r][c] - '0');
    if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= m ||
        board[new_r][new_c] == 'H')
      continue;
    int temp = dfs(new_r, new_c);
    if (temp == -1)
      return -1;
    res = max(res, temp);
  }
  dp[r][c] = res + 1;
  visited[r][c] = false;
  return res + 1;
}

int main(void) {
  cin >> n >> m;
  board.assign(n, vector<char>(m));
  dp.assign(n, vector<int>(m, 0));
  visited.assign(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      board[i][j] = str[j];
    }
  }

  cout << dfs(0, 0);
  return 0;
}