//21 09 21

#include <iostream>
using namespace std;

int parent_node[1000000+1];

void Union_set(int a, int b)
{
    parent_node[parent_node[b]] = parent_node[parent_node[a]];
}

int Renew_parent_node(int a)
{
    if (parent_node[a]==a)
        return a;
    else
    {
        parent_node[a] = Renew_parent_node(parent_node[a]);
        return parent_node[a];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>>n>>m;

    for (int i=0; i<=n; i++)
        parent_node[i] = i;

    while (m--)
    {
        bool oper;
        int a, b;

        cin>>oper>>a>>b;

        int parent_a = Renew_parent_node(a);
        int parent_b = Renew_parent_node(b);

        if (!oper)
        {
            if (parent_a <= parent_b)
                Union_set(a, b);
            else
                Union_set(b, a);
        }
        else
        {
            if (parent_a == parent_b)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }

    return 0;
}