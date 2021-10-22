// 21/10/22

#include <iostream>
#include <queue>
using namespace std;

int game[101];
int dp[101];

void Input(void)
{
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n+m; i++)
    {
        int start, finish;
        cin >> start >> finish;
        game[start] = finish;
    }
    for (int i=1; i<=100; i++)
        dp[i] = 987654321;
}

void Solve(void)
{
    queue<int> q;
    dp[1] = 0;
    q.push(1);

    while (1)
    {
        int node = q.front();
        q.pop();

        if (node == 100)
            break;

        for (int i=1; i<=6; i++)
        {
            if (node+i <=100 && dp[node+i] >dp[node]+1)
            {
                if (game[node+i] && dp[game[node+i]] > dp[node]+1)
                {
                    dp[game[node+i]] = dp[node]+1;
                    q.push(game[node+i]);
                }
                if (game[node+i] == 0)
                {
                    dp[node+i] = dp[node] + 1;
                    q.push(node+i);
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solve();
    cout<<dp[100];
    return 0;
}