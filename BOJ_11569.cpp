//21 10 05

#include <iostream>
using namespace std;
const int MAX = 100000;

int arr[MAX];
int tree[4*MAX];
int n, m;

void init_tree(int node, int start, int finish)
{
    if (start == finish)
        tree[node] = arr[start];
    else
    {
        int mid = (start+finish)/2;
        init_tree(node*2, start, mid);
        init_tree(node*2+1, mid+1, finish);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int Find_sum(int node, int tree_start, int tree_finish, int seg_left, int seg_right)
{
    if (seg_left > tree_finish || seg_right < tree_start)
        return 0;
    if (seg_left <= tree_start && seg_right >= tree_finish)
        return tree[node];
    
    int tree_mid = (tree_start+tree_finish)/2;
    return Find_sum(node*2, tree_start, tree_mid, seg_left, seg_right)
    + Find_sum(node*2+1, tree_mid+1, tree_finish, seg_left, seg_right);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>arr[i];

    init_tree(1,0,n-1);

    while (m--)
    {
        int a, b;
        cin>>a>>b;
        cout<<Find_sum(1,0,n-1,a-1,b-1)<<"\n";
    }

    return 0;
}