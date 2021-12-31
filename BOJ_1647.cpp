// 21 / 12 / 31

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, groups;
long long cost;
vector<int> parent;
vector<pair<int, pair<int, int>>> edge;

int parentNode(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = parentNode(parent[node]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    groups = n;
    sort(edge.begin(), edge.end());

    int i = 0;
    while (groups > 2)
    {
        int nowCost = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;

        int parentNode1 = parentNode(node1);
        int parentNode2 = parentNode(node2);

        if (parentNode1 != parentNode2)
        {
            cost += nowCost;
            groups--;
            parent[parentNode1] = parentNode2;
        }
        i++;
    }
    cout << cost;
    return 0;
}