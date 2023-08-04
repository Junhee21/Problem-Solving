#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int id = 0;
vector<vector<int>> edges;
vector<bool> visited;
vector<int> ids;
stack<int> s;
vector<vector<int>> sccs;

bool compare(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int search_scc(int node) {
  ids[node] = id++;
  int minNode = ids[node];
  s.push(node);

  for (auto &child : edges[node]) {
    if (ids[child] == -1) {
      minNode = min(minNode, search_scc(child));
    } else if (!visited[child]) {
      minNode = min(minNode, ids[child]);
    }
  }

  if (minNode == ids[node]) {
    vector<int> scc;
    while (!s.empty()) {
      int t = s.top();
      s.pop();
      scc.push_back(t);
      visited[t] = true;
      if (t == node)
        break;
    }
    sort(scc.begin(), scc.end());
    sccs.push_back(scc);
  }
  return minNode;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int v, e;
  cin >> v >> e;
  edges.reserve(v + 1);
  visited.resize(v + 1, false);
  ids.resize(v + 1, -1);
  while (e--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }
  for (int i = 1; i <= v; i++) {
    if (ids[i] == -1) {
      search_scc(i);
    }
  }

  sort(sccs.begin(), sccs.end(), compare);

  cout << sccs.size() << "\n";
  for (auto &i : sccs) {
    for (auto &j : i) {
      cout << j << " ";
    }
    cout << -1 << "\n";
  }
  return 0;
}