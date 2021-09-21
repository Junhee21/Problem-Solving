//21 09 21

#include<iostream>
using namespace std;

int parent_node[500000];

int Find_parent(int node)
{
    if (parent_node[node] == node)
        return node;
    else
    {
        parent_node[node] = Find_parent(parent_node[node]);
        return parent_node[node];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for (int i=0; i<n; i++)
        parent_node[i] = i;

    int cycle_num=0, check_num=0;
    for ( int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;

        if (check_num)
            continue;

        int parent_a = Find_parent(a);
        int parent_b = Find_parent(b);

        if (parent_a==parent_b)
        {
            cycle_num = i;
            check_num = 1;
        }
        else
        {
            if (parent_a<=parent_b)
                parent_node[parent_b] = parent_a;
            else
                parent_node[parent_a] = parent_b;
        }
    }

    if (check_num)
        cout<<cycle_num;
    else
        cout<<0;

    return 0;
}