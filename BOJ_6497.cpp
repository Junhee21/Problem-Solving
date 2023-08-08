#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int a, b, len;
};

vector<Edge> edges;
vector<int> parent_node;

bool compare(const Edge &a, const Edge &b) { return a.len < b.len; }

int find_parent(int node) {
  if (parent_node[node] != node) {
    parent_node[node] = find_parent(parent_node[node]);
  }

  return parent_node[node];
}

int main(void) {
  while (true) {
    int n, k;
    cin >> n >> k;
    if (n == 0 && k == 0)
      return 0;
    edges.resize(k);
    parent_node.resize(n);
    for (int i = 0; i < n; i++)
      parent_node[i] = i;
    int sum_edges = 0;
    for (int i = 0; i < k; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      edges[i] = Edge{a, b, c};
      sum_edges += c;
    }
    sort(edges.begin(), edges.end(), compare);
    int cnt = 0;
    for (int i = 0; i < k; i++) {
      Edge edge = edges[i];
      if (find_parent(edge.a) != find_parent(edge.b)) {
        cnt++;
        sum_edges -= edge.len;
        parent_node[parent_node[edge.a]] = parent_node[parent_node[edge.b]];
      }
      if (cnt == n - 1) {
        cout << sum_edges << "\n";
        break;
      }
    }
  }
  return 0;
}