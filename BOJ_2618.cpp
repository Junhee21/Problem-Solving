//21 10 04

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> //memset
#include <cstdlib> //abs
using namespace std;

vector<pair<int, int>> accident;
int dp[1010][1010];
int n, w;

int cost(int x, int y)
{
    return abs(accident[x].first-accident[y].first)+abs(accident[x].second-accident[y].second);
}

int Police(int x, int y)
{
    int now_acci = max(x,y) + 1;
    if (now_acci == w+2)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    int cost1 = cost(x, now_acci);
    int cost2 = cost(y, now_acci);
    return dp[x][y] = min(cost1+Police(now_acci, y), cost2+Police(x, now_acci));
}

void Backtracking(int x, int y)
{
    int now_acci = max(x, y) + 1;
    if (now_acci == w+2)
        return;
    
    if (dp[now_acci][y] + cost(x,now_acci) < dp[x][now_acci] + cost(y,now_acci))
    {
        cout<<1<<"\n";
        Backtracking(now_acci, y);
    }
    else
    {
        cout<<2<<"\n";
        Backtracking(x, now_acci);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>w;
    accident.push_back({1, 1});
    accident.push_back({n, n});
    for (int i=0; i<w; i++)
    {
        int a, b;
        cin>>a>>b;
        accident.push_back({a,b});
    }
    memset(dp, -1, sizeof(dp));

    cout << Police(0,1) <<"\n";
    Backtracking(0, 1);

    return 0;
}