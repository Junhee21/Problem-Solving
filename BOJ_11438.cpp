// 21/11/16

#include <iostream>
#include <vector>
using namespace std;

int n, q;
const int maxDepth = 17;
vector<vector<int>> edge;
vector<vector<int>> parent;
vector<bool> check;
vector<int> depth;

void findDepth(int node, int level, int parentNode)
{
    check[node] = true;
    depth[node] = level;
    parent[node][0] = parentNode;
    for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
    {
        if (check[*iter])
            continue;
        findDepth(*iter, level + 1, node);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    edge.assign(n + 1, vector<int>(0));
    parent.assign(n + 1, vector<int>(maxDepth, 0));
    depth.assign(n + 1, 0);
    check.assign(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    findDepth(1, 0, 0);

    for (int i = 1; i < maxDepth; i++)
    {
        for (int j = 1; j <= n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
    }

    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (depth[x] > depth[y])
            swap(x, y);

        int depthGap = depth[y] - depth[x];
        int step = 0;
        while (depthGap != 0)
        {
            if (depthGap % 2 == 1)
                y = parent[y][step];
            if (depthGap == 1)
                break;
            step++;
            depthGap /= 2;
        }

        if (x == y)
            cout << x << "\n";
        else
        {
            for (int i = maxDepth - 1; i >= 0; i--)
            {
                if (parent[x][i] != parent[y][i])
                {
                    x = parent[x][i];
                    y = parent[y][i];
                }
            }
            cout << parent[x][0] << "\n";
        }
    }
    return 0;
}