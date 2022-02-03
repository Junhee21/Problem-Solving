// 22 / 2 / 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<pair<int, int>, pair<int, int>>> arr;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr.push_back({{-b, -c}, {-d, a}});
    }

    int g, s, b;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second.second == k)
        {
            g = arr[i].first.first;
            s = arr[i].first.second;
            b = arr[i].second.first;
        }
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if ((arr[i].first.first == g) && (arr[i].first.second == s) && (arr[i].second.first == b))
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}