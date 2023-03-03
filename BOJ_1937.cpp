#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> forest;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int answer = 0;
int n;

void search(int r, int c) {
  if (dp[r][c] != 0)
    return;
  int num = 0;
  for (int i = 0; i < 4; i++) {
    int newR = r + dir[i].first;
    int newC = c + dir[i].second;
    if (newR == -1 || newR == n || newC == -1 || newC == n)
      continue;
    if (forest[newR][newC] <= forest[r][c])
      continue;
    search(newR, newC);
    num = num > dp[newR][newC] ? num : dp[newR][newC];
  }
  dp[r][c] = 1 + num;
  answer = dp[r][c] > answer ? dp[r][c] : answer;
}

int main(void) {
  cin >> n;

  dp.assign(n, vector<int>(n, 0));
  forest.assign(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> forest[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      search(i, j);
    }
  }

  cout << answer;

  return 0;
}