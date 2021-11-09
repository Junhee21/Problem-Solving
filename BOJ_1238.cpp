// 21/11/09

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x;
vector<pair<int, int>> edge[1001];
vector<vector<int>> cost;

void input()
{
    cin >> n >> m >> x;
    cost.assign(n+1, vector<int>(n+1, 987654321));
    while (m--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        edge[a].push_back({b, c});
    }
}

int howCost(int node, int target)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, node});

    while (!pq.empty())
    {
        int now_cost = -pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        for (int i=0; i<(int)edge[now_node].size(); i++)
        {
            int new_cost = now_cost+edge[now_node][i].second;
            int new_node = edge[now_node][i].first;

            if (new_cost < cost[node][new_node])
            {
                cost[node][new_node] = new_cost;
                pq.push({-new_cost, new_node});
            }
        }
    }

    return cost[node][target];
}

int whoMost()
{
    priority_queue<int> answer_list;
    for (int i=1; i<=n; i++)
    {
        if (i==x)
            continue;

        answer_list.push(howCost(x, i) + howCost(i, x));
    }

    return answer_list.top();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << whoMost();
    return 0;
}