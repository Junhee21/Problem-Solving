// 22 / 1 / 6

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int town, oil;
vector<pair<int, int>> arr;
priority_queue<int> pq;

int solve(void)
{
    int answer = 0;
    int location = 0;
    for (int i = 0; i <= n; i++)
    {
        int gasStation = arr[i].first;
        int getOil = arr[i].second;
        oil -= (gasStation - location);
        location = gasStation;
        while (oil < 0)
        {
            if (pq.empty())
                return -1;
            oil += pq.top();
            pq.pop();
            answer++;
        }
        pq.push(getOil);
    }

    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    cin >> town >> oil;
    arr.push_back({town, 0});
    sort(arr.begin(), arr.end());
    cout << solve();
    return 0;
}