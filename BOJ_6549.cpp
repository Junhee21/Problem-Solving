//21 10 05

#include <iostream>
using namespace std;
const int MAX = 100000+1;

int arr[MAX];
int tree[4*MAX][2];
int n;
long long max_area;

void Init_tree(int node, int start, int finish)
{
    if (start == finish)
    {
        tree[node][0] = arr[start];
        tree[node][1] = start;
        return;
    }

    int mid = (start+finish)/2;
    Init_tree(node*2, start, mid);
    Init_tree(node*2+1, mid+1, finish);

    if (tree[node*2+1][0] < tree[node*2][0])
    {
        tree[node][0] = tree[node*2+1][0];
        tree[node][1] = tree[node*2+1][1];
    }
    else
    {
        tree[node][0] = tree[node*2][0];
        tree[node][1] = tree[node*2][1];
    }
}

int Search_min(int node, int start, int finish, int seg_left, int seg_right)
{
    if (seg_left > finish || seg_right < start)
        return 0;
    if (seg_left <= start && seg_right >= finish)
        return node;
    
    int mid = (start+finish)/2;

    int temp1 = Search_min(node*2, start, mid, seg_left, seg_right);
    int temp2 = Search_min(node*2+1, mid+1, finish, seg_left, seg_right);

    if (tree[temp2][0] < tree[temp1][0])
        return temp2;
    else
        return temp1;
}

void Solve(int seg_left, int seg_right)
{   
    if (seg_left > seg_right)
        return;

    int temp= Search_min(1, 1, n, seg_left, seg_right);
    int height = tree[temp][0];
    int height_index = tree[temp][1];
    if (((long long)height) * ((long long)(seg_right-seg_left+1)) > max_area)
        max_area = ((long long)height) * ((long long)(seg_right-seg_left+1));

    Solve(seg_left, height_index-1);
    for (int i=height_index+1; i<=seg_right; i++)
    {
        if (arr[i] > arr[height_index])
        {
            Solve(i, seg_right);
            break;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    tree[0][0] = 1000000001;
    while (1)
    {
        cin>>n;
        if (!n)
            break;
        
        for (int i=1; i<=n; i++)
            cin>>arr[i];

        max_area = 0;
        Init_tree(1, 1, n);
        Solve(1, n);
        cout<<max_area<<"\n";
    }

    return 0;
}