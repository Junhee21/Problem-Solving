//21 09 28

#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100000+1];
int subtree_size[100000+1];
int n, r, q;

void Count_subtree(int root, int parent)
{
    subtree_size[root] = 1;
    for (auto iter = tree[root].begin(); iter != tree[root].end(); iter++)
    {
        if(*iter != parent)
        {
            Count_subtree(*iter, root);
            subtree_size[root] += subtree_size[*iter];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>r>>q;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    Count_subtree(r, -1);

    while (q--)
    {
        int x;
        cin>>x;
        cout<<subtree_size[x]<<"\n";
    }

    
    return 0;
}