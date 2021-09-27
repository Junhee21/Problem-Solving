//21 09 27

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000;

vector<vector<int>> distance_island;
vector<pair<int, pair<int, int>>> bridge;
vector<int> parent;
vector<int> da = {-1, 0, 1, 0};
vector<int> db = { 0, 1, 0, -1};
int matrix[10][10];
int n=0, m=0, num=1, total_distance = 0;

void Search_island_size(int a, int b)
{
    matrix[a][b] = num;
    for (int i=0; i<4; i++)
    {
        if (a+da[i]>=0 && a+da[i]<n && b+db[i]<m && b+db[i]>=0 && matrix[a+da[i]][b+db[i]]==1)
            Search_island_size(a+da[i], b+db[i]);
    }
}

void Count_island(void)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (matrix[i][j] == 1)
            {
                num++;
                Search_island_size(i, j);
            }
        }
    }
}

void Explore_sea(int a, int b, int direction)
{
    int d = 0;
    for (int i=1; 1; i++)
    {
        if (a+i*da[direction]==-1 || a+i*da[direction]==n || b+i*db[direction]==-1 || b+i*db[direction]==m)
            break;        
        if (matrix[a+i*da[direction]][b+i*db[direction]])
        {
            int new_island = matrix[a+i*da[direction]][b+i*db[direction]] - 2;
            if (d>1 && d < distance_island[matrix[a][b]-2][new_island])
                distance_island[matrix[a][b]-2][new_island] = d;
            break;
        }
        d++;
    }
}

void Search_distance_island(void)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (matrix[i][j])
            {
                for (int k=0; k<4; k++)
                {
                    if (i+da[k]>=0 && i+da[k]<n && j+db[k]<m && j+db[k]>=0 && matrix[i+da[k]][j+db[k]]==0)
                        Explore_sea(i, j, k);
                }
            }
        }
    }
}

void Make_bridge(void)
{
    for (int i=0; i<num-1; i++)
    {
        for (int j=0; j<num-1; j++)
        {
            if (i==j)
                continue;
            if (distance_island[i][j] < INF)
                bridge.push_back({distance_island[i][j], {i ,j}});
        }
    }
    sort(bridge.begin(), bridge.end());
}

int Find_parent(int node)
{
    if (parent[node] == node)
        return node;
    parent[node] = Find_parent(parent[node]);
    return parent[node];
}

void Union_island(void)
{
    parent.assign(num-1, 0);
    for (int i=0; i<num-1; i++)
        parent[i] = i;

    for (auto iter = bridge.begin(); iter!=bridge.end(); iter++)
    {
        int node1 = (*iter).second.first;
        int node2 = (*iter).second.second;
        int parent1 = Find_parent(node1);
        int parent2 = Find_parent(node2);

        if (parent1 == parent2)
            continue;
        parent[parent2] = parent1;
        total_distance += distance_island[node1][node2];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cin>>matrix[i][j];
    }

    Count_island();
    distance_island.assign(num-1, vector<int>(num-1, INF));
    Search_distance_island();
    Make_bridge();
    Union_island();

    int c = 0;
    for (int i=0; i<num-1; i++)
    {
        if (parent[i]==i)
            c++;
    }
    if (c==1)
        cout<<total_distance;
    else
        cout<<-1;
    
    return 0;
}