//21 09 09

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000+1;

vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int v=0, top_node = 0, diameter=0;

void DFS(int node, int cost)
{
    if (visited[node])
        return;

    visited[node] = true;

    if (cost>diameter)
    {
        diameter = cost;
        top_node = node;
    }
    
    for (int i=0; i<tree[node].size(); i++)
        DFS(tree[node][i].first, cost+tree[node][i].second);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>v;

    for (int i=0; i<v; i++)
    {
        int start;
        cin>>start;
        while (1)
        {
            int node, length;
            cin>>node;
            if (node == -1)
                break;
            cin>>length;
            tree[start].push_back({node, length});
        }
    }

    fill_n(visited, v+1, false);

    DFS(1,0);

    diameter = 0;
    fill_n(visited, v+1, false);

    DFS(top_node, 0);

    cout<<diameter;

    return 0;
}