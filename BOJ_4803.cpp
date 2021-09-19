//21 09 19

#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[500+1];
bool visited[501];
int check_tree;

void DFS(int node, int before_node)
{
    visited[node] = true;
    for (int i=0; i<tree[node].size(); i++)
    {
        if ((tree[node][i] != before_node) && visited[tree[node][i]])
            check_tree = 0;
        if ((tree[node][i] != before_node) && !visited[tree[node][i]])
            DFS(tree[node][i], node);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int c=1; 1; c++)
    {
        int n, v;
        cin>>n>>v;

        if (!n && !v)
            break;

        for (int i=1; i<=n; i++)
            tree[i].clear();

        for (int i=0; i<v; i++)
        {
            int a, b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        fill_n(visited, n+1, false);
        int num_tree = 0;

        for (int i=1; i<=n; i++)
        {
            if (!visited[i])
            {
                check_tree = 1;
                DFS(i, 0);
                    if (check_tree)
                num_tree++;
            }
        }

        cout<<"Case "<<c;
        if (!num_tree)
            cout<<": No trees.\n";
        else if(num_tree == 1)
            cout<<": There is one tree.\n";
        else
            cout<<": A forest of "<<num_tree<<" trees.\n";
    }

    return 0;           
}