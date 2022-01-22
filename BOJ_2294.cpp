// 22 / 1 / 22

#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int n, k;
vector<int> coin;
vector<int> dp;

int main(void)
{
    cin >> n >> k;
    coin.assign(n, 0);
    dp.assign(k + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + coin[i] <= k; j++)
        {
            if (dp[j + coin[i]] > dp[j] + 1)
                dp[j + coin[i]] = dp[j] + 1;
        }
    }
    if (dp[k] == INF)
        cout << -1;
    else
        cout << dp[k];
    return 0;
}