// 21/11/14

#include <iostream>
#include <vector>
using namespace std;

vector<bool> check;
vector<int> depth;
vector<vector<int>> edge;
vector<vector<int>> parent;
int n, root;
const int maxDepth = 15;

void init()
{
    cin >> n;
    check.assign(n + 1, true);
    depth.assign(n + 1, 0);
    edge.assign(n + 1, vector<int>(0));
    parent.assign(n + 1, vector<int>(maxDepth, -1));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        check[b] = false;
        edge[a].push_back(b);
        parent[b][0] = a;
    }
}

void findRoot()
{
    for (int i = 1; i <= n; i++)
    {
        if (check[i])
        {
            root = i;
            break;
        }
    }
}

void searchDepth(int node, int level)
{
    depth[node] = level;
    for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
    {
        searchDepth(*iter, level + 1);
    }
}

void initParent()
{
    for (int i = 1; i < maxDepth; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (parent[j][i - 1] == -1)
                parent[j][i] = -1;
            else
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

void solve()
{
    int x, y;
    cin >> x >> y;
    if (depth[x] > depth[y])
        swap(x, y);

    int depthGap = depth[y] - depth[x];
    int step = 0;
    while (depthGap != 0)
    {
        if (depthGap == 1)
        {
            y = parent[y][step];
            break;
        }
        if (depthGap % 2 == 1)
            y = parent[y][step];
        depthGap /= 2;
        step++;
    }

    if (x == y)
    {
        cout << x << "\n";
        return;
    }

    step = maxDepth - 1;
    while (1)
    {
        if (parent[x][step] != parent[y][step])
        {
            x = parent[x][step];
            y = parent[y][step];
        }
        if (step == 0)
            break;
        step--;
    }
    cout << parent[x][0] << "\n";
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        init();
        findRoot();
        searchDepth(root, 0);
        initParent();
        solve();
    }

    return 0;
}