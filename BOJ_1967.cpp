//21 09 19

#include <iostream>
#include <vector>
using namespace std;
const int MAX=10000+1;

int top_node=0, diameter=0;
bool visited[MAX];
vector<pair<int,int>>tree[MAX];

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

int main (void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v;
    cin>>v;

    for (int i=0; i<v-1; i++)
    {
        int parent_node, child_node, cost;
        cin>>parent_node>>child_node>>cost;
        tree[parent_node].push_back({child_node, cost});
        tree[child_node].push_back({parent_node, cost});
    }

    fill_n(visited, v+1, false);
    DFS(1,0);

    diameter = 0;
    fill_n(visited, v+1, false);
    DFS(top_node,0);

    cout<<diameter;

    return 0;
}