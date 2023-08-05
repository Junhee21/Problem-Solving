#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> sccs;
vector<vector<int>> edges;
vector<int> ids;
vector<bool> visited;
stack<int> s;
int id = 1;

int search_scc(int current) {
  int res = id++;
  ids[current] = res;
  s.push(current);
  for (auto &i : edges[current]) {
    if (ids[i] == 0) {
      res = min(res, search_scc(i));
    } else if (!visited[i]) {
      res = min(res, ids[i]);
    }
  }

  if (res == ids[current]) {
    vector<int> scc;
    while (true) {
      int t = s.top();
      s.pop();
      scc.push_back(t);
      visited[t] = true;
      if (t == current) {
        sccs.push_back(scc);
        break;
      }
    }
  }

  return res;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  edges.assign(2 * n + 1, vector<int>());
  ids.assign(2 * n + 1, 0);
  visited.assign(2 * n + 1, false);
  while (m--) {
    int a, b;
    cin >> a >> b;
    edges[-a + n].push_back(b + n);
    edges[-b + n].push_back(a + n);
  }

  for (int i = 0; i <= 2 * n; i++) {
    if (i == n)
      continue;
    if (ids[i] == 0) {
      search_scc(i);
    }
  }

  for (auto &i : sccs) {
    vector<bool> checked(n + 1, false);
    for (auto &j : i) {
      int temp = j - n < 0 ? n - j : j - n;
      if (checked[temp]) {
        cout << 0;
        return 0;
      } else {
        checked[temp] = true;
      }
    }
  }
  cout << 1;
  return 0;
}