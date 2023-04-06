#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<vector<long long>> dp;
int n;

long long search(int r, int c) {
  if (r < 0 || r >= n)
    return 0;
  if (c < 0 || c >= n)
    return 0;
  if (dp[r][c] != -1)
    return dp[r][c];
  if (board[r][c] == 0)
    return 0;

  dp[r][c] = search(r + board[r][c], c) + search(r, c + board[r][c]);
  return dp[r][c];
}

int main(void) {
  cin >> n;
  board.assign(n, vector<int>(n, 0));
  dp.assign(n, vector<long long>(n, -1));
  dp[n - 1][n - 1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
  cout << search(0, 0);
  return 0;
}