// 22 / 1 / 7

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x, y;
queue<pair<int, int>> q;
vector<bool> check;
vector<vector<int>> edge;

int solve(void)
{
    q.push({x, 0});
    check[x] = true;
    while (!q.empty())
    {
        int node = q.front().first;
        int level = q.front().second;
        if (node == y)
            return level;
        q.pop();
        for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
        {
            if (check[*iter])
                continue;
            q.push({(*iter), level + 1});
            check[*iter] = true;
        }
    }
    return -1;
}

int main(void)
{
    cin >> n >> x >> y;
    check.assign(n + 1, false);
    edge.assign(n + 1, vector<int>(0));
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cout << solve();
    return 0;
}