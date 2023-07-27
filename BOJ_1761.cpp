#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> tree;
vector<int> level;

void init_tree(int node, int parent, int len, int lev) {
  tree[node][0] = {parent, len};
  level[node] = lev;
  for (auto iter = edges[node].begin(); iter != edges[node].end(); iter++) {
    if (parent == (*iter).first)
      continue;
    init_tree((*iter).first, node, (*iter).second, lev + 1);
  }
}

int get_length(int a, int b) {
  int len = 0;
  if (level[b] > level[a])
    swap(a, b);
  if (level[a] != level[b]) {
    for (int i = 15; i >= 0; i--) {
      if (level[tree[a][i].first] >= level[b]) {
        len += tree[a][i].second;
        a = tree[a][i].first;
      }
    }
  }
  if (a != b) {
    for (int i = 15; i >= 0; i--) {
      if (tree[a][i].first != tree[b][i].first) {
        len += tree[a][i].second;
        len += tree[b][i].second;
        a = tree[a][i].first;
        b = tree[b][i].first;
      }
    }
    len += tree[a][0].second;
    len += tree[b][0].second;
  }
  return len;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cout.tie(0);

  int n;
  cin >> n;
  edges.assign(n + 1, vector<pair<int, int>>());
  tree.assign(n + 1, vector<pair<int, int>>(16, {0, 0}));
  level.assign(n + 1, 0);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
  init_tree(1, 0, 0, 1);
  for (int i = 1; i < 16; i++) {
    for (int j = 1; j <= n; j++) {
      pair<int, int> mid = tree[j][i - 1];
      tree[j][i] = {tree[mid.first][i - 1].first,
                    mid.second + tree[mid.first][i - 1].second};
    }
  }

  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << get_length(a, b) << "\n";
  }
  return 0;
}