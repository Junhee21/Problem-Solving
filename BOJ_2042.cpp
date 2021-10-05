//21 10 05

#include <iostream>
using namespace std;
const int MAX = 1000000;

long long arr[MAX+1];
long long tree[4*MAX];
int n, m, k;

void init_tree(int node, int start, int finish)
{
    if (start == finish)
        tree[node] = arr[start];
    else
    {
        int mid = (start+finish)/2;
        init_tree(node*2, start, mid);
        init_tree(node*2+1, mid+1, finish);;
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

void Update_tree(int node, int start, int finish, int index, long long num)
{
    if (start == finish && index == start)
    {
        tree[node] = num;
        return;
    }
    if (index >= start && index <= finish)
    {
        int mid = (start+finish)/2;
        Update_tree(node*2, start, mid, index, num);
        Update_tree(node*2+1, mid+1, finish, index, num);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

long long Find_sum(int node, int start, int finish, int seg_left, int seg_right)
{
    if (seg_left > finish || seg_right < start)
        return 0;
    if (seg_left <= start && seg_right >= finish)
        return tree[node];
    
    int mid = (start+finish)/2;
    return Find_sum(node*2, start, mid, seg_left, seg_right)
            +Find_sum(node*2+1, mid+1, finish, seg_left, seg_right);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        cin>>arr[i];
    
    init_tree(1,1,n);
    
    for (int i=0; i<(m+k); i++)
    {
        int a, b;
        long long c;
        cin>>a>>b>>c;
        if (a==1)
            Update_tree(1, 1, n, b, c);
        else
            cout<<Find_sum(1, 1, n, b, c)<<"\n";
    }

    return 0;
}