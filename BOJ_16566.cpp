// 21 / 12 / 29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> card;
vector<bool> check;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    card.assign(m, 0);
    check.assign(m, false);
    for (int i = 0; i < m; i++)
        cin >> card[i];
    sort(card.begin(), card.end());

    while (k--)
    {
        int x;
        cin >> x;
        int upperIndex = upper_bound(card.begin(), card.end(), x) - card.begin();
        while (check[upperIndex])
            upperIndex++;
        check[upperIndex] = true;
        cout << card[upperIndex] << "\n";
    }

    return 0;
}