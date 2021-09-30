//21 09 30

#include <iostream>
using namespace std;

int n;
int dp[16][(1<<16)-1];
int cost[16][16];

int DFS(int node, int state)
{
    if (state == 1)
    {
        if (!cost[0][node])
            return 987654321;
        return cost[0][node];
    }
        

    if (dp[node][state])
        return dp[node][state];

    int x = 987654321;
    for (int i=1; i<n; i++)
    {
        if (!cost[i][node])
            continue;
        if (state&(1<<i))
        {
            if(cost[i][node] + DFS(i, (state&(~(1<<i)))) < x)
                x = cost[i][node] + DFS(i, (state&(~(1<<i))));
        }
    }
    dp[node][state] = x;
    return x;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin >> cost[i][j];
    }

    cout << DFS(0, (1<<n)-1);

    return 0;
}