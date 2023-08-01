#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int node, cost;
  bool dir;
  Node(int node, int cost, bool dir) {
    this->node = node;
    this->cost = cost;
    this->dir = dir;
  }
};

struct BfsNode {
  int num, cost;
};

vector<vector<Node>> edges;
vector<int> indegrees;
vector<int> maxCosts;
vector<bool> visited;
queue<int> q;
queue<BfsNode> bfs_q;

int main(void) {
  int n, m;
  cin >> n >> m;
  edges.resize(n + 1);
  indegrees.assign(n + 1, 0);
  maxCosts.resize(n + 1);
  visited.assign(n + 1, false);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges[a].push_back(*(new Node(b, c, true)));
    edges[b].push_back(*(new Node(a, c, false)));
    indegrees[b]++;
  }
  int s, e;
  cin >> s >> e;

  q.push(s);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto iter = edges[node].begin(); iter != edges[node].end(); iter++) {
      if (!(*iter).dir)
        continue;
      if (maxCosts[node] + (*iter).cost > maxCosts[(*iter).node]) {
        maxCosts[(*iter).node] = maxCosts[node] + (*iter).cost;
      }
      indegrees[(*iter).node]--;
      if (indegrees[(*iter).node] == 0) {
        q.push((*iter).node);
      }
    }
  }

  int max_cost = maxCosts[e];
  int edge_cnt = 0;

  bfs_q.push({e, 0});
  while (!bfs_q.empty()) {
    BfsNode node = bfs_q.front();
    bfs_q.pop();
    for (auto iter = edges[node.num].begin(); iter != edges[node.num].end();
         iter++) {
      if ((*iter).dir)
        continue;
      if (node.cost + (*iter).cost + maxCosts[(*iter).node] == max_cost) {
        edge_cnt++;
        if (!visited[(*iter).node]) {
          bfs_q.push({(*iter).node, node.cost + (*iter).cost});
          visited[(*iter).node] = true;
        }
      }
    }
  }

  cout << max_cost << "\n" << edge_cnt;
  return 0;
}