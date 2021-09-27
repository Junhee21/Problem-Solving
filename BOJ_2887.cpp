//21 09 29

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> dx;
vector<pair<int, int>> dy;
vector<pair<int, int>> dz;
vector<pair<int, pair<int, int>>> tunnel;
int parent[100000];
long long total_distance = 0;
int n;

int Find_parent(int node)
{
    if (parent[node] == node)
        return node;
    parent[node] = Find_parent(parent[node]);
    return parent[node];
}

void Make_tunnel(void)
{
    for (auto iter=tunnel.begin(); iter!=tunnel.end(); iter++)
    {
        int node1 = (*iter).second.first;
        int node2 = (*iter).second.second;
        int parent1 = Find_parent(node1);
        int parent2 = Find_parent(node2);

        if (parent1 == parent2)
            continue;
        parent[parent2] = parent1;
        total_distance += (*iter).first;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for (int i=0; i<n; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        dx.push_back({x, i});
        dy.push_back({y, i});
        dz.push_back({z, i});
        parent[i] = i;
    }

    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    sort(dz.begin(), dz.end());

    for (int i=0; i<n-1; i++)
    {
        tunnel.push_back({dy[i+1].first-dy[i].first, {dy[i+1].second, dy[i].second}});
        tunnel.push_back({dz[i+1].first-dz[i].first, {dz[i+1].second, dz[i].second}});
        tunnel.push_back({dx[i+1].first-dx[i].first, {dx[i+1].second, dx[i].second}});
    }
    sort(tunnel.begin(), tunnel.end());

    Make_tunnel();
    cout<<total_distance;

    return 0;
}