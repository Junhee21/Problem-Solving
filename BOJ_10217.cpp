#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

struct Edge {
  int e, time, cost;
  Edge(int e, int cost, int time) {
    this->e = e;
    this->cost = cost;
    this->time = time;
  }
};

struct Q {
  int node, cost, time;
  Q(int node, int cost, int time) {
    this->node = node;
    this->cost = cost;
    this->time = time;
  }
  bool operator<(const Q &second) const { return time > second.time; }
};

int t, n, m, k, a, b, c, d;
vector<vector<int>> dp;
vector<vector<Edge *>> edges;

bool compare(Edge *a, Edge *b) { return a->time < b->time; }

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;

    dp.assign(n + 1, vector<int>(m + 1, INF));
    edges.resize(n + 1);
    for (int i = 0; i < k; i++) {
      cin >> a >> b >> c >> d;
      edges[a].push_back(new Edge(b, c, d));
    }

    for (int i = 0; i <= m; i++) {
      dp[1][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
      sort(edges[i].begin(), edges[i].end(), compare);
    }

    priority_queue<Q> pq;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
      int start_time = pq.top().time;
      int start_cost = pq.top().cost;
      int start_node = pq.top().node;
      if (start_node == n)
        break;
      pq.pop();

      if (dp[start_node][start_cost] < start_time)
        continue;

      for (int i = 0; i < edges[start_node].size(); i++) {
        int next_time = start_time + edges[start_node][i]->time;
        int next_cost = start_cost + edges[start_node][i]->cost;
        int next_node = edges[start_node][i]->e;

        if (next_cost > m)
          continue;
        if (dp[next_node][next_cost] > next_time) {
          for (int j = next_cost; j <= m; j++) {
            if (dp[next_node][j] <= next_time) {
              break;
            }
            dp[next_node][j] = next_time;
          }
          dp[next_node][next_cost] = next_time;
          pq.push({next_node, next_cost, next_time});
        }
      }
    }
    int min = INF;
    for (int i = 0; i <= m; i++) {
      if (dp[n][i] < min)
        min = dp[n][i];
    }
    if (min == INF)
      cout << "Poor KCM\n";
    else
      cout << min << "\n";
  }
  return 0;
}