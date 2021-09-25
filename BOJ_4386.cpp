//21 09 25

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<double,double>>star_location;
vector<pair<double, pair<int, int>>>star_length;
int parent[100];
int n;
double total_length = 0;

int Find_parent(int node)
{
    if (parent[node] == node)
        return node;
    parent[node] = Find_parent(parent[node]);
    return parent[node];
}

void Make_MST(void)
{
    for (auto iter = star_length.begin(); iter!=star_length.end(); iter++)
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
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<n; i++)
    {
        double x, y;
        cin >> x >> y;
        star_location.push_back({x, y});
        parent[i] = i;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i==j)
                continue;
            star_length.push_back({sqrt(pow(star_location[i].first-star_location[j].first, 2)
            + pow(star_location[i].second-star_location[j].second, 2)), {i, j}});
        }
    }

    sort(star_length.begin(), star_length.end());

    Make_MST();

    cout<< total_length;

    return 0;
}