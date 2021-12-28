// 21 / 12 / 27

#include <iostream>
#include <vector>
using namespace std;

vector<int> price;
vector<int> dp;
int n, answer;

int main(void)
{
    cin >> n;
    price.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> price[i];

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] >= price[i])
            continue;
        for (int j = 0; j + i <= n; j++)
        {
            if (price[i] + dp[j] > dp[i + j])
                dp[i + j] = price[i] + dp[j];
        }
    }

    cout << dp[n];

    return 0;
}