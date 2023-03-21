#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Item {
public:
  int height;
  int cnt = 1;
  Item(int height) { this->height = height; }
};

vector<int> height;
stack<Item> s;

int main(void) {
  int n;
  cin >> n;
  height.assign(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> height[i];
  }

  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    Item item(height[i]);
    while (!s.empty() && (height[i] >= s.top().height)) {
      if (height[i] == s.top().height) {
        item.cnt = s.top().cnt + 1;
      }
      cnt += s.top().cnt;
      s.pop();
    }
    if (!s.empty()) {
      cnt++;
    }
    s.push(item);
  }

  cout << cnt;
  return 0;
}