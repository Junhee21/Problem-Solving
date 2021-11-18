// 21/11/18

#include <iostream>
#include <vector>
using namespace std;

const int maxDepth = 17;
int n, m;
vector<vector<pair<int, long long>>> edge;
vector<vector<pair<int, long long>>> parent; // parent, cost
vector<int> depth;
vector<bool> check;

void solve(int order)
{
    int x, y, z;
    cin >> x >> y;
    int tempX = x;
    int tempY = y;
    if (order == 2)
        cin >> z;

    int xToLca = 0;
    int yToLca = 0;
    long long totalCost = 0;

    if (depth[x] < depth[y])
    {
        int depthGap = depth[y] - depth[x];
        int step = 0;
        int length = 1;
        while (depthGap != 0)
        {
            if (depthGap % 2 == 1)
            {
                totalCost += parent[y][step].second;
                y = parent[y][step].first;
                yToLca += length;
            }
            if (depthGap == 1)
                break;
            depthGap /= 2;
            step++;
            length *= 2;
        }
    }
    else
    {
        int depthGap = depth[x] - depth[y];
        int step = 0;
        int length = 1;
        while (depthGap != 0)
        {
            if (depthGap % 2 == 1)
            {
                totalCost += parent[x][step].second;
                x = parent[x][step].first;
                xToLca += length;
            }
            if (depthGap == 1)
                break;
            depthGap /= 2;
            step++;
            length *= 2;
        }
    }

    for (int i=maxDepth-1; i>=0; i--)
    {
        if (parent[x][i].first != parent[y][i].first)
        {
            totalCost += parent[x][i].second;
            totalCost += parent[y][i].second;
            x = parent[x][i].first;
            y = parent[y][i].first;
            int length = 1;
            for (int j=0; j<i; j++)
            {
                length *= 2;
            }
            xToLca += length;
            yToLca += length;
        }
    }

    if (order == 1)
    {
        if (x==y)
            cout << totalCost <<"\n";
        else
        {
            totalCost += parent[x][0].second;
            totalCost += parent[y][0].second;
            cout << totalCost <<"\n";
        }
    }

    else
    {
        z--;
        if (x!=y)
        {
            xToLca ++;
            yToLca ++;
        }

        if (xToLca >= z)
        {
            int step = 0;
            while (z!=0)
            {
                if (z % 2 == 1)
                    tempX = parent[tempX][step].first;
                if (z==1)
                    break;
                z /= 2;
                step++;
            }
            cout << tempX <<"\n";
        }
        else
        {
            z -= xToLca;
            z = (yToLca - z);
            int step = 0;
            while (z!=0)
            {
                if (z % 2 == 1)
                    tempY = parent[tempY][step].first;
                if (z==1)
                    break;
                z /= 2;
                step++;
            }
            cout << tempY <<"\n";
        }
    }
}

void findDepth(int node, int level)
{
    check[node] = true;
    depth[node] = level;
    for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
    {
        if (check[(*iter).first])
            continue;
        parent[(*iter).first][0] = {node, (*iter).second};
        findDepth((*iter).first, level + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    edge.assign(n + 1, vector<pair<int,long long >>(0));
    depth.assign(n + 1, 0);
    check.assign(n + 1, false);
    parent.assign(n + 1, vector<pair<int, long long>>(maxDepth, {0, 0}));
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    findDepth(1, 0);

    for (int i = 1; i < maxDepth; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i].first = parent[parent[j][i - 1].first][i - 1].first;
            parent[j][i].second = parent[parent[j][i - 1].first][i - 1].second + parent[j][i - 1].second;
        }
    }

    cin >> m;
    while (m--)
    {
        int order;
        cin >> order;
        solve(order);
    }
    return 0;
}