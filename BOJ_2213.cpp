//21 09 28

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000+1;

vector<int> edge[MAX];
vector<int> node_list;
int dp[MAX][2];
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

    dp[node][1] = cost[node];
    for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
    {
        dp[node][0] += max(dp[*iter][0], dp[*iter][1]);
        dp[node][1] += dp[*iter][0];
    }
}

void Back_track(int node, int parent, bool state)
{
    if (!state)
    {
        for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
        {
            if (*iter == parent)
                continue;
            if (dp[*iter][1] > dp[*iter][0])
                Back_track(*iter, node, 1);
            else
                Back_track(*iter, node, 0);
        }
    }
    else
    {
        node_list.push_back(node);
        for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
        {
            if (*iter == parent)
                continue;
            Back_track(*iter, node, 0);
        }
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
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1, -1);

    int total_size;
    if (dp[1][0] > dp[1][1])
    {
        total_size = dp[1][0];
        Back_track(1, -1 , 0);
    }
    else
    {
        total_size = dp[1][1];
        Back_track(1, -1 , 1);
    }
    sort(node_list.begin(), node_list.end());

    cout << total_size <<"\n";
    for (auto iter = node_list.begin(); iter!=node_list.end(); iter++)
        cout<<*iter<<" ";
    
    return 0;
}