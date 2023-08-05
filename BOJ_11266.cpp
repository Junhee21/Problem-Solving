#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edges;
vector<int> ids;
vector<int> articulation_points;
int id = 1;

int dfs(int current, int parent, bool isRoot) {
  int res = id++;
  ids[current] = res;
  int child_cnt = 0;
  bool isArticulationPoint = false;
  for (auto &i : edges[current]) {
    if (i == parent)
      continue;
    if (ids[i] != 0) {
      res = min(res, ids[i]);
      continue;
    }
    child_cnt++;
    int child_res = dfs(i, current, false);
    if (!isArticulationPoint && !isRoot && child_res >= ids[current]) {
      articulation_points.push_back(current);
      isArticulationPoint = true;
    }
    res = min(res, child_res);
  }
  if (isRoot && child_cnt >= 2) {
    articulation_points.push_back(current);
  }
  return res;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int v, e;
  cin >> v >> e;
  edges.assign(v + 1, vector<int>());
  ids.assign(v + 1, 0);
  while (e--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for (int i = 1; i <= v; i++) {
    if (ids[i] == 0)
      dfs(i, 0, true);
  }
  sort(articulation_points.begin(), articulation_points.end());
  cout << articulation_points.size() << "\n";
  for (auto &i : articulation_points) {
    cout << i << " ";
  }
  return 0;
}