#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> isFriend;
vector<bool> isVisited;

int search(int index) {
  if (isVisited[index])
    return 0;
  isVisited[index] = true;
  int maxLength = 0;
  for (auto iter : isFriend[index]) {
    int length = search(iter);
    if (length > 4)
      return 999;
    maxLength = length > maxLength ? length : maxLength;
  }
  isVisited[index] = false;
  return maxLength + 1;
}

int main(void) {
  int m;
  cin >> n >> m;
  isVisited.assign(n, false);
  isFriend.assign(n, vector<int>(0));

  while (m--) {
    int a, b;
    cin >> a >> b;
    isFriend[a].push_back(b);
    isFriend[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    if (search(i) >= 5) {
      cout << 1;
      return 0;
    }
  }

  cout << 0;
  return 0;
}