#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Num {
  int value;
  int idx;
  Num(int value, int idx) {
    this->value = value;
    this->idx = idx;
  }
};

bool compare(Num *a, Num *b) {
  return a->value == b->value ? a->idx < b->idx : a->value < b->value;
}

vector<Num *> arr;
vector<int> seg_tree;

void insert_segtree(int arr_idx, int seg_idx, int le, int ri) {
  if (le == ri) {
    seg_tree[seg_idx] = 1;
    return;
  }
  if (arr_idx <= (le + ri) / 2) {
    insert_segtree(arr_idx, seg_idx * 2 + 1, le, (le + ri) / 2);
  } else {
    insert_segtree(arr_idx, seg_idx * 2 + 2, (le + ri) / 2 + 1, ri);
  }
  seg_tree[seg_idx] = seg_tree[seg_idx * 2 + 1] + seg_tree[seg_idx * 2 + 2];
}

long long search_segtree(int target_le, int target_ri, int idx, int le,
                         int ri) {
  if (target_le > target_ri)
    return 0;
  if (target_le == le && target_ri == ri)
    return seg_tree[idx];
  if (target_le <= (le + ri) / 2) {
    long long res = 0;
    res += search_segtree(target_le, (le + ri) / 2, idx * 2 + 1, le,
                          (le + ri) / 2);
    res += seg_tree[idx * 2 + 2];
    return res;
  } else {
    return search_segtree(target_le, target_ri, idx * 2 + 2, (le + ri) / 2 + 1,
                          ri);
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = new Num(num, i);
  }
  sort(arr.begin(), arr.end(), compare);
  long long res = 0;
  seg_tree.assign(n * 4, 0);
  for (int i = 0; i < n; i++) {
    res += search_segtree(arr[i]->idx + 1, n - 1, 0, 0, n - 1);
    insert_segtree(arr[i]->idx, 0, 0, n - 1);
  }
  cout << res;
  return 0;
}