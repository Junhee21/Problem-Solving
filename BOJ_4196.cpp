#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> edges;
vector<int> ids;
vector<int> sccs;
int id = 0;
int scc_id = 0;

int dfs(int node, stack<int> &s) {
  int res = id;
  ids[node] = id++;
  s.push(node);

  for (auto &i : edges[node]) {
    if (ids[i] == -1)
      res = min(res, dfs(i, s));
    else if (sccs[i] == -1)
      res = min(res, ids[i]);
  }

  if (res == ids[node]) {
    while (!s.empty()) {
      int t = s.top();
      s.pop();
      sccs[t] = scc_id;
      if (t == node)
        break;
    }
    scc_id++;
  }

  return res;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    edges.assign(n + 1, vector<int>());
    ids.assign(n + 1, -1);
    sccs.assign(n + 1, -1);
    id = 0;
    scc_id = 0;
    stack<int> s;
    while (m--) {
      int a, b;
      cin >> a >> b;
      edges[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
      if (ids[i] == -1)
        dfs(i, s);
    }
    vector<int> scc_indegree(scc_id, 0);
    for (int i = 1; i <= n; i++) {
      for (auto &j : edges[i]) {
        if (sccs[i] != sccs[j])
          scc_indegree[sccs[j]]++;
      }
    }
    int res = 0;
    for (int &i : scc_indegree) {
      if (i == 0)
        res++;
    }
    cout << res << "\n";
  }
  return 0;
}