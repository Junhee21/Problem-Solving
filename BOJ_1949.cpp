//21 09 29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000+1;

vector<int> edge[MAX];
int dp[MAX][3];
int cost[MAX];
int n;

void dfs(int node, int parent)
{
    for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
    {
        if (*iter == parent)
            continue;
        dfs(*iter, node);
    }

    //dp[i][0] = i 가 우수마을, [1] = 아닐때, [2] = i, 자식 다 우수마을 아니여서 부모가 무조건 우수여야함
    dp[node][0] = cost[node];
    for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
    {
        if (*iter == parent)
            continue;
        dp[node][0] += max(dp[*iter][1], dp[*iter][2]);
        dp[node][1] += max(dp[*iter][0], dp[*iter][1]);
        dp[node][2] += dp[*iter][1];
    }    
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for (int i=1; i<=n; i++)
        cin>>cost[i];
    
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a>> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1, -1);
    vector<int> whatMax = {dp[1][0], dp[1][1], dp[1][2]};
    cout << *max_element(whatMax.begin(), whatMax.end());

    return 0;
}