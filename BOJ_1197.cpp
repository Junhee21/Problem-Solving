//21 09 25

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int, int>>> road;
int parent_node[10000+1];
int total_cost = 0;

int Find_parent(int node)
{
    if (parent_node[node] == node)
        return node;
    parent_node[node] = Find_parent(parent_node[node]);
    return parent_node[node];
}

void Make_MST(void)
{
    for (auto iter = road.begin(); iter!=road.end(); iter++)
    {
        int node1 = (*iter).second.first;
        int node2 = (*iter).second.second;

        int parent1 = Find_parent(node1);
        int parent2 = Find_parent(node2);

        if (parent1 != parent2)
        {
            parent_node[parent2] = parent1;
            total_cost += (*iter).first;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int v, e;
    cin>>v>>e;

    while (e--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        road.push_back({c, {a, b}});
    }

    for (int i=1; i<=v; i++)
        parent_node[i] = i;

    sort(road.begin(), road.end());

    Make_MST();

    cout<<total_cost;

    return 0;
}