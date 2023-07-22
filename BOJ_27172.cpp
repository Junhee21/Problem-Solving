#include <iostream>
#include <vector>
using namespace std;

vector<bool> checked(1000001, false);
vector<int> scores(1000001, 0);
vector<int> cards;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  cards.assign(n, 0);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    cards[i] = num;
    checked[num] = true;
  }

  for (int i = 0; i < n; i++) {
    int card = cards[i];
    for (int j = card * 2; j <= 1000000; j += card) {
      if (!checked[j])
        continue;
      scores[card]++;
      scores[j]--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << scores[cards[i]] << " ";
  }
  return 0;
}