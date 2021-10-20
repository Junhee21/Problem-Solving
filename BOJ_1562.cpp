// 21/10/19

#include <iostream>
using namespace std;
const int divided = 1000000000;

int n;
long long dp[100][10][1<<10];

void Solve(void)
{
    for (int i=1; i<10; i++)
    {
        dp[0][i][1<<i] = 1;
    }

    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<10; j++)
        {
            for (int k=1; k<(1<<10); k++)
            {
                if (dp[i][j][k] == 0)
                    continue;
                if (j+1<10)
                {
                    dp[i+1][j+1][k|(1<<(j+1))] += dp[i][j][k];
                    dp[i+1][j+1][k|(1<<(j+1))] %= divided;
                }
                if (j-1>=0)
                {
                    dp[i+1][j-1][k|(1<<(j-1))] += dp[i][j][k];
                    dp[i+1][j-1][k|(1<<(j-1))] %= divided;
                }
            }
        }
    }

    long long answer = 0;
    for (int i=0; i<10; i++)
        answer += dp[n-1][i][(1<<10)-1];

    cout << answer%divided;
}

int main(void)
{
    cin >> n;
    Solve();

    return 0;
}