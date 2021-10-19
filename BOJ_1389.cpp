// 21-10-19

#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;

int n, m;
int cost[101][101];

void Solve(void)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (cost[i][j])
                continue;
            cost[i][j] = INF;
        }
        cost[i][i] = 0;
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int k=1; k<=n; k++)
            {
                if (cost[j][k] > cost[j][i] + cost[i][k])
                    cost[j][k] = cost[j][i] + cost[i][k] ;
            }
        }
    }
}

int answer(void)
{
    int minimum = 987654321;
    int min_index = 0;
    for (int i=1; i<=n; i++)
    {
        int x = 0;
        for (int j=1; j<=n; j++)
            x+=cost[i][j];
        if (x < minimum)
        {
            minimum = x;
            min_index = i;
        }
    }
    return min_index;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        cost[node1][node2] = 1;
        cost[node2][node1] = 1;
    }

    Solve();
    cout<< answer();

    return 0;
}