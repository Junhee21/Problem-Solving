#include <iostream>
#include <vector>
using namespace std;

vector<int> segtree(4000000, 0);

void add_candy(int num, int cnt, int le, int ri, int idx) {
  if (num < le || num > ri)
    return;
  segtree[idx] += cnt;
  if (le == ri)
    return;
  add_candy(num, cnt, le, (le + ri) / 2, idx * 2 + 1);
  add_candy(num, cnt, (le + ri) / 2 + 1, ri, idx * 2 + 2);
}

void get_candy(int num, int le, int ri, int idx) {
  segtree[idx]--;
  if (le == ri) {
    cout << le << "\n";
    return;
  }
  if (segtree[idx * 2 + 1] >= num) {
    get_candy(num, le, (le + ri) / 2, idx * 2 + 1);
  } else {
    get_candy(num - segtree[idx * 2 + 1], (le + ri) / 2 + 1, ri, idx * 2 + 2);
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    if (a == 1) {
      int b;
      cin >> b;
      get_candy(b, 1, 1000000, 0);
    } else {
      int b, c;
      cin >> b >> c;
      add_candy(b, c, 1, 1000000, 0);
    }
  }
  return 0;
}