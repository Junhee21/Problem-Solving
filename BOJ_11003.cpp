// 22 / 1 / 4

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, len;
vector<int> arr;
priority_queue<pair<int, int>> pq;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> len;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        pq.push({-arr[i], i});
        pair<int, int> x = pq.top();
        while (pq.top().second < i - len + 1)
            pq.pop();
        cout << -pq.top().first << " ";
    }

    return 0;
}