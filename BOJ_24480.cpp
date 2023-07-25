#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, r, cnt = 1;
vector<int> visited;
vector<vector<int>> edges;

void dfs(int node) {
  visited[node] = cnt++;
  sort(edges[node].begin(), edges[node].end(), greater<int>());

  for (auto iter = edges[node].begin(); iter != edges[node].end(); iter++) {
    if (visited[*iter] == 0) {
      dfs(*iter);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> r;
  visited.assign(n + 1, 0);
  edges.assign(n + 1, vector<int>());

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