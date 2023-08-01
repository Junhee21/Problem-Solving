#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int idx, num;
};
vector<Node> segtree;
vector<int> arr;

void init_tree(int s, int e, int idx) {
  if (s == e) {
    segtree[idx] = {s, arr[s]};
  } else {
    init_tree(s, (s + e) / 2, idx * 2 + 1);
    init_tree((s + e) / 2 + 1, e, idx * 2 + 2);
    segtree[idx] = segtree[idx * 2 + 1].num <= segtree[idx * 2 + 2].num
                       ? segtree[idx * 2 + 1]
                       : segtree[idx * 2 + 2];
  }
}

void change_tree(int target, int num, int s, int e, int idx) {
  if (s == e) {
    segtree[idx].num = num;
    return;
  }

  if (target <= (s + e) / 2) {
    change_tree(target, num, s, (s + e) / 2, idx * 2 + 1);
  } else {
    change_tree(target, num, (s + e) / 2 + 1, e, idx * 2 + 2);
  }
  segtree[idx] = segtree[idx * 2 + 1].num <= segtree[idx * 2 + 2].num
                     ? segtree[idx * 2 + 1]
                     : segtree[idx * 2 + 2];
}

Node get_min(int le, int ri, int s, int e, int idx) {
  if (le == s && ri == e) {
    return segtree[idx];
  }

  Node le_min = {0, 1000000001};
  Node ri_min = {0, 1000000001};
  if (ri <= (s + e) / 2) {
    le_min = get_min(le, ri, s, (s + e) / 2, idx * 2 + 1);
  } else if (le <= (s + e) / 2) {
    le_min = get_min(le, (s + e) / 2, s, (s + e) / 2, idx * 2 + 1);
    ri_min = get_min((s + e) / 2 + 1, ri, (s + e) / 2 + 1, e, idx * 2 + 2);
  } else {
    ri_min = get_min(le, ri, (s + e) / 2 + 1, e, idx * 2 + 2);
  }

  return le_min.num <= ri_min.num ? le_min : ri_min;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  segtree.assign(n * 4, {0, 0});
  arr.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  init_tree(1, n, 0);
  int m;
  cin >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      change_tree(b, c, 1, n, 0);
    } else {
      cout << get_min(b, c, 1, n, 0).idx << "\n";
    }
  }

  return 0;
}