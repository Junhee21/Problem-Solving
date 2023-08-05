#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;

struct Edge {
  int node;
  int len;
  bool isOpened = true;
  Edge(int node, int len) {
    this->node = node;
    this->len = len;
  }
};

struct cmp {
  bool operator()(Edge a, Edge b) { return a.len > b.len; }
};

vector<vector<Edge>> edges;
vector<vector<Edge>> reverse_edges;
vector<int> distances;
vector<bool> visited;

int search_edge(int s, int d) {
  distances[s] = 0;
  priority_queue<Edge, vector<Edge>, cmp> q;
  q.push({s, 0});

  while (!q.empty()) {
    Edge t = q.top();
    q.pop();

    if (t.node == d) {
      return distances[t.node];
    }
    if (distances[t.node] < t.len)
      continue;
    for (auto &iter : edges[t.node]) {
      if (!iter.isOpened)
        continue;
      if (distances[t.node] + iter.len < distances[iter.node]) {
        distances[iter.node] = distances[t.node] + iter.len;
        q.push({iter.node, distances[iter.node]});
      }
    }
  }
  return -1;
}

void remove_shortest(int node) {
  if (distances[node] == 0)
    return;
  visited[node] = true;
  for (auto &i : reverse_edges[node]) {
    if (distances[i.node] + i.len == distances[node]) {
      for (int j = 0; j < edges[i.node].size(); j++) {
        if (edges[i.node][j].node == node) {
          edges[i.node][j].isOpened = false;
          break;
        }
      }
      if (!visited[i.node])
        remove_shortest(i.node);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      return 0;
    int s, d;
    cin >> s >> d;
    edges.assign(n, vector<Edge>());
    reverse_edges.assign(n, vector<Edge>());
    distances.assign(n, INF);
    visited.assign(n, false);
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      edges[a].push_back(Edge(b, c));
      reverse_edges[b].push_back(Edge(a, c));
    }

    search_edge(s, d);
    remove_shortest(d);
    distances.assign(n, INF);
    cout << search_edge(s, d) << "\n";
  }
  return 0;
}