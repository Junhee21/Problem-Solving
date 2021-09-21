//21 09 21

#include <iostream>
using namespace std;

int parent_node[200+1];

int Find_parent(int x)
{
    if (parent_node[x] == x)
        return x;
    else
    {
        parent_node[x] = Find_parent(parent_node[x]);
        return parent_node[x];
    }
}

void Union_set(int a, int b)
{
    parent_node[parent_node[b]] = parent_node[a];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for (int i=1; i<=n; i++)
        parent_node[i] = i;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            bool can_go;
            cin>>can_go;

            if (can_go)
            {
                int i_parent = Find_parent(i);
                int j_parent = Find_parent(j);

                if (i_parent <= j_parent)
                    Union_set(i, j);
                else
                    Union_set(j, i);
            }
        }
    }

    int first_parent_node;
    int i=0;
    for (i=0; i<m; i++)
    {
        int y;
        cin>>y;
        int y_parent = Find_parent(y);
        if (i==0)
            first_parent_node = y_parent;
        else
        {
            if (y_parent != first_parent_node)
            {
                cout<<"NO";
                break;
            }
        }
    }

    if (i==m)
        cout<<"YES";

    return 0;
}