//21 09 06 > 21 10 11

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int tracking[101][101];
int bus[101][101];
int n, m, a, b, c;

void Floyd(void)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            for (int k=1; k<=n; k++)
            {
                if (bus[j][k] > bus[j][i] + bus[i][k])
                {
                    bus[j][k] = bus[j][i] + bus[i][k];
                    tracking[j][k] = i;
                }
            }
        }
    }
}

void Back_tracking(int x, int y, vector<int>&temp)
{
    if (x==y || bus[x][y]==INF)
        return;
    if (tracking[x][y] == x)
    {
        temp.push_back(x);
        return;
    }

    int z = tracking[x][y];
    Back_tracking(x,z, temp);
    Back_tracking(z,y, temp);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            bus[i][j] = INF;
            tracking[i][j] = i;
        }
        bus[i][i] = 0;
    }
    while (m--)
    {
        cin >> a>> b>> c;
        if (bus[a][b]>c)
            bus[a][b] = c;
    }

    Floyd();

    for (int i=1; i<=n ;i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (bus[i][j] == INF)
                cout << 0 << " ";
            else
                cout << bus[i][j] << " ";
        }
        cout<<"\n";
    }

    for (int i=1; i<=n ;i++)
    {
        for (int j=1; j<=n; j++)
        {
            vector<int> temp;
            Back_tracking(i, j, temp);
            if (temp.empty())
            {
                cout<<0<<"\n";
                continue;
            }
            cout<<((int)temp.size())+1<<" ";
            for (auto iter = temp.begin(); iter!=temp.end(); iter++)
                cout<<*iter<<" ";
            cout<<j<<" ";
            cout<<"\n";
        }
    }

    return 0;
}