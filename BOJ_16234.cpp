#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int n, L, R;
struct Node {
  int x;
  int y;
};
vector<vector<int>> population;
vector<vector<bool>> isVisited;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int getAbs(int x, int y) { return x > y ? x - y : y - x; }

void search(int r, int c, vector<Node> &nodes) {
  isVisited[r][c] = true;
  nodes.push_back(Node{r, c});
  for (int i = 0; i < 4; i++) {
    int newR = r + dir[i].first;
    int newC = c + dir[i].second;
    if (newR == -1 || newR == n || newC == -1 || newC == n)
      continue;
    if (isVisited[newR][newC])
      continue;
    int gap = getAbs(population[r][c], population[newR][newC]);
    if (gap < L || gap > R)
      continue;
    search(newR, newC, nodes);
  }
}

bool open() {
  bool isMoved = false;
  isVisited.assign(n, vector<bool>(n, false));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (isVisited[i][j])
        continue;
      vector<Node> nodes;
      search(i, j, nodes);
      int num = nodes.size();
      if (num == 1)
        continue;
      isMoved = true;
      int sum = 0;
      for (auto iter : nodes) {
        sum += population[iter.x][iter.y];
      }
      int avg = (int)floor((double)(sum) / (double)(num));
      for (auto iter : nodes) {
        population[iter.x][iter.y] = avg;
      }
    }
  }

  return isMoved;
}

int main(void) {
  cin >> n >> L >> R;
  population.assign(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> population[i][j];
    }
  }

  int cnt = 0;
  while (true) {
    if (!open()) {
      cout << cnt;
      return 0;
    }
    cnt++;
  }
  return 0;
}