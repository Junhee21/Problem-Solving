//21 09 26

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<double, double>> god_site;
vector<pair<double, pair<int, int>>> god_length;
int parent[1000 + 1];
double total_length = 0;

int Find_parent(int node)
{
    if (parent[node] == node)
        return node;
    parent[node] = Find_parent(parent[node]);
    return parent[node];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed;
    cout.precision(2);

    int n, m;
    cin>>n>>m;
    god_site.push_back({0,0});
    for (int i=1; i<=n; i++)
    {
        double x, y;
        cin >> x >> y;
        god_site.push_back({x, y});
        parent[i] = i;
    }
    for (int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;

        int a_p = Find_parent(a);
        int b_p = Find_parent(b);
        
        parent[a_p] = b_p;
    }

    //모든 별의 길이 다 계산
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i==j)
                continue;
            double length_data = sqrt(pow(god_site[i].first - god_site[j].first, 2)
            + pow(god_site[i].second - god_site[j].second, 2));
            god_length.push_back({length_data, {i, j}});
        }
    }

    sort(god_length.begin(), god_length.end());

    for (auto iter = god_length.begin(); iter!=god_length.end(); iter++)
    {
        int node1 = (*iter).second.first;
        int node2 = (*iter).second.second;

        int parent1 = Find_parent(node1);
        int parent2 = Find_parent(node2);

        if (parent1 == parent2)
            continue;
        
        parent[parent2] = parent1;
        total_length += (*iter).first;
    }

    cout<<total_length;

    return 0;
}