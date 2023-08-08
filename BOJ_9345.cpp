#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int max, min;
};

vector<Node> seg_tree;
vector<int> dvds;

void init_tree(int idx, int seg_le, int seg_ri) {
  seg_tree[idx] = Node{seg_ri, seg_le};
  if (seg_le == seg_ri) {
    return;
  }
  init_tree(idx * 2 + 1, seg_le, (seg_le + seg_ri) / 2);
  init_tree(idx * 2 + 2, (seg_le + seg_ri) / 2 + 1, seg_ri);
}

Node borrow_dvds(int le, int ri, int idx, int seg_le, int seg_ri) {
  if (le == seg_le && ri == seg_ri)
    return seg_tree[idx];

  int seg_mid = (seg_le + seg_ri) / 2;
  if (ri <= seg_mid)
    return borrow_dvds(le, ri, idx * 2 + 1, seg_le, seg_mid);
  else if (le <= seg_mid) {
    Node left = borrow_dvds(le, seg_mid, idx * 2 + 1, seg_le, seg_mid);
    Node right = borrow_dvds(seg_mid + 1, ri, idx * 2 + 2, seg_mid + 1, seg_ri);
    int mx = max(left.max, right.max);
    int mn = min(left.min, right.min);
    return Node{mx, mn};
  } else
    return borrow_dvds(le, ri, idx * 2 + 2, seg_mid + 1, seg_ri);
}

void change_dvd(int dvd, int target_idx, int idx, int seg_le, int seg_ri) {
  if (seg_le == seg_ri) {
    seg_tree[idx] = Node{dvd, dvd};
    return;
  }

  if (target_idx <= (seg_le + seg_ri) / 2)
    change_dvd(dvd, target_idx, idx * 2 + 1, seg_le, (seg_le + seg_ri) / 2);
  else
    change_dvd(dvd, target_idx, idx * 2 + 2, (seg_le + seg_ri) / 2 + 1, seg_ri);
  Node le_node = seg_tree[idx * 2 + 1];
  Node ri_node = seg_tree[idx * 2 + 2];
  seg_tree[idx] =
      Node{max(le_node.max, ri_node.max), min(le_node.min, ri_node.min)};
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;

    seg_tree.resize(n * 4);
    dvds.resize(n);
    init_tree(0, 0, n - 1);
    for (int i = 0; i < n; i++)
      dvds[i] = i;

    while (k--) {
      int a;
      cin >> a;
      if (a == 0) {
        int b, c;
        cin >> b >> c;
        int dvd_b = dvds[b];
        int dvd_c = dvds[c];
        dvds[b] = dvd_c;
        dvds[c] = dvd_b;
        change_dvd(dvd_c, b, 0, 0, n - 1);
        change_dvd(dvd_b, c, 0, 0, n - 1);
      } else {
        int b, c;
        cin >> b >> c;
        Node node = borrow_dvds(b, c, 0, 0, n - 1);
        if (node.max == c && node.min == b)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
  return 0;
}