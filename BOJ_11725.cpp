//21 09 09

#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> tree[MAX];
bool visited[MAX];
int parent[MAX];
int n;

void Solve(int parent_node)
{
    visited[parent_node] = true;
    for (int i=0; i<tree[parent_node].size(); i++)
    {
        if (!visited[tree[parent_node][i]])
        {
            parent[tree[parent_node][i]] = parent_node;
            Solve(tree[parent_node][i]);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for (int i=0; i<n-1; i++)
    {
        int node1, node2;
        cin>>node1>>node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    Solve(1);

    for (int i=2; i<=n; i++)
        cout<<parent[i]<<"\n";
    
    return 0;
}