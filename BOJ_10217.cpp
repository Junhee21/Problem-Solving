#include <algorithm>
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

struct Edge {
  int e, time, cost;
  Edge(int e, int cost, int time) {
    this->e = e;
    this->cost = cost;
    this->time = time;
  }
};

int t, n, m, k, a, b, c, d;
vector<vector<int>> dp;
vector<vector<Edge *>> edges;

int dfs(int node, int cost) {
  if (node == n)
    return 0;
  if (dp[node][cost] != -1)
    return dp[node][cost];
  dp[node][cost] = INF;
  for (auto &iter : edges[node]) {
    if (cost + iter->cost > m)
      continue;
    dp[node][cost] =
        min(dp[node][cost], dfs(iter->e, cost + iter->cost) + iter->time);
  }
  return dp[node][cost];
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    dp.assign(n + 1, vector<int>(m + 1, -1));
    edges.resize(n + 1);
    for (int i = 0; i < k; i++) {
      cin >> a >> b >> c >> d;
      edges[a].push_back(new Edge(b, c, d));
    }

    int result = dfs(1, 0);
    if (result == INF)
      cout << "Poor KCM\n";
    else
      cout << result << "\n";
  }
  return 0;
}