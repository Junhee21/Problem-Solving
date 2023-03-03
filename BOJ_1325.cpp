#include <iostream>
#include <vector>
using namespace std;

int n, maxNum = 0;
vector<vector<int>> edge;
vector<int> arr;
vector<bool> isVisited;

int search(int index) {
  if (isVisited[index])
    return 0;
  isVisited[index] = true;
  int sum = 1;
  for (auto iter : edge[index]) {
    sum += search(iter);
  }
  return sum;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m;
  cin >> n >> m;
  edge.assign(n + 1, vector<int>(0));
  arr.assign(n + 1, 0);
  while (m--) {
    int a, b;
    cin >> a >> b;
    edge[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    isVisited.assign(n + 1, false);
    int sum = search(i);
    arr[i] = sum;
    maxNum = sum > maxNum ? sum : maxNum;
  }

  for (int i = 1; i <= n; i++) {
    if (arr[i] == maxNum)
      cout << i << " ";
  }

  return 0;
}