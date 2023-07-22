#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> candies;
vector<bool> checked;
vector<vector<int>> edges;
vector<pair<int, int>> candy_friend;
vector<vector<int>> dp;

pair<int, int> search_candy(int node) {
  if (checked[node])
    return {0, 0};
  int candy_cnt = candies[node];
  int friend_cnt = 1;
  checked[node] = true;
  for (auto iter = edges[node].begin(); iter != edges[node].end(); iter++) {
    pair<int, int> child_candy_friend = search_candy(*iter);
    candy_cnt += child_candy_friend.first;
    friend_cnt += child_candy_friend.second;
  }
  return {candy_cnt, friend_cnt};
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  candies.assign(n + 1, 0);
  checked.assign(n + 1, false);
  edges.assign(n + 1, vector<int>());
  for (int i = 1; i <= n; i++) {
    cin >> candies[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (checked[i])
      continue;
    candy_friend.push_back(search_candy(i));
  }

  dp.assign(candy_friend.size() + 1, vector<int>(k, 0));
  for (int i = 0; i < candy_friend.size(); i++) {
    int candy_cnt = candy_friend[i].first;
    int friend_cnt = candy_friend[i].second;
    for (int j = 0; j < k; j++) {
      if (j < friend_cnt) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = dp[i][j - friend_cnt] + candy_cnt > dp[i][j]
                           ? dp[i][j - friend_cnt] + candy_cnt
                           : dp[i][j];
      }
    }
  }
  cout << dp[candy_friend.size()][k - 1];
  return 0;
}