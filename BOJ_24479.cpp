#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, r;

vector<vector<int>> edges;
vector<int> visited;

int cnt = 1;

void dfs(int node) {
  visited[node] = cnt;
  cnt++;
  sort(edges[node].begin(), edges[node].end());

  for (auto iter = edges[node].begin(); iter != edges[node].end(); iter++) {
    if (visited[*iter] != 0)
      continue;
    dfs(*iter);
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  edges.assign(n + 1, vector<int>());
  visited.assign(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  dfs(r);

  for (int i = 1; i <= n; i++) {
    cout << visited[i] << "\n";
  }
  return 0;
}