//21 09 30

#include <iostream>
using namespace std;

int dp[20][(1<<20)-1];
int edge[20][20];
int n;

int DFS(int num, int state)
{
    if (num==0)
    {
        for (int i=0; i<n; i++)
        {
            if (state&(1<<i))
            {
                dp[num][state] = edge[num][i];
                return dp[num][state];
            }
        }
    }
    if (dp[num][state])
        return dp[num][state];
    
    int x = 987654321;
    for (int i=0; i<n; i++)
    {
        if (!(state &(1<<i)))
            continue;
        int temp_state = state&(~(1<<i));
        if (DFS(num-1, temp_state) + edge[num][i] < x)
            x = dp[num-1][temp_state] + edge[num][i];
    }
    dp[num][state] = x;
    return dp[num][state];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin >> edge[i][j];
    }

    cout << DFS(n-1, (1<<n)-1);

    return 0;
}