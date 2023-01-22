#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct GuitarString {
  int packagePrice;
  int onePrice;
};
int n, m;

int findMinPackagePrice(vector<GuitarString> brands) {
  int minPrice = 987654321;
  for (auto ptr = brands.begin(); ptr != brands.end(); ptr++) {
    if (ptr->packagePrice < minPrice)
      minPrice = ptr->packagePrice;
  }
  return minPrice;
}

int findMinOnePrice(vector<GuitarString> brands) {
  int minPrice = 987654321;
  for (auto ptr = brands.begin(); ptr != brands.end(); ptr++) {
    if (ptr->onePrice < minPrice)
      minPrice = ptr->onePrice;
  }
  return minPrice;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int totalCost = 0;

  cin >> n >> m;
  vector<GuitarString> brands;
  for (int i = 0; i < m; i++) {
    GuitarString gs;
    cin >> gs.packagePrice >> gs.onePrice;
    brands.push_back(gs);
  }
  int minPackagePrice = findMinPackagePrice(brands);
  int minOnePrice = findMinOnePrice(brands);

  while (n > 0) {
    if (n >= 6) {
      int _cost = min(minPackagePrice, minOnePrice * 6);
      totalCost += (_cost * (n / 6));
      n %= 6;
    } else {
      int _cost = min(minPackagePrice, minOnePrice * n);
      totalCost += _cost;
      break;
    }
  }
  cout << totalCost;
  return 0;
}