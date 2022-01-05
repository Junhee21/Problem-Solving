// 21 / 12 / 24

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> pq;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    jewel.assign(n, pair<int, int>(0, 0));
    bag.assign(k, 0);

    for (int i = 0; i < n; i++)
        cin >> jewel[i].first >> jewel[i].second;
    for (int i = 0; i < k; i++)
        cin >> bag[i];

    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    long long answer = 0;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        int nowBag = bag[i];
        while ((j < n) && (jewel[j].first <= nowBag))
            pq.push(jewel[j++].second);
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer;
    return 0;
}