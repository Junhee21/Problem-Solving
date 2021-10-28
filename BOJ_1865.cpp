// 21/10/28

#include <iostream>
using namespace std;

int edge[501][501];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;
    while (TC--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
                edge[i][j] = 987654321;
        }

        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (edge[a][b] > c)
                edge[a][b] = c;
            if (edge[b][a] > c)
                edge[b][a] = c;
        }

        while (w--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (edge[a][b] > (-1)*c)
                edge[a][b] = (-1)*c;
        }

        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                for (int k=1; k<=n; k++)
                {
                    if (edge[j][k] > edge[j][i] + edge[i][k])
                        edge[j][k] = edge[j][i] + edge[i][k];
                }
            }
        }

        bool answer = false;
        for (int i=1; i<=n; i++)
        {
            if (edge[i][i] < 0)
            {
                answer = true;
                break;
            }
        }

        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}