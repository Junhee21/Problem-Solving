//21 10 05

#include <iostream>
using namespace std;
const int MAX = 100000+1;
const int INF = 1000000001;

int arr[MAX];
int tree[MAX*4][2]; //[0] = max, [1] = min
int n, m;

void Init_tree(int node, int start, int finish)
{
    if (start == finish)
    {
        tree[node][0] = arr[start];
        tree[node][1] = arr[start];
        return;
    }
    int mid = (start + finish)/2;
    Init_tree(node*2, start, mid);
    Init_tree(node*2+1, mid+1, finish);
    tree[node][0] = (tree[node*2][0]>tree[node*2+1][0]) ? tree[node*2][0] : tree[node*2+1][0];
    tree[node][1] = (tree[node*2][1]<tree[node*2+1][1]) ? tree[node*2][1] : tree[node*2+1][1];
}

pair<int, int> what_min_max(int node, int start, int finish, int seg_left, int seg_right)
{
    if (seg_left > finish || seg_right <start)
        return {INF, 0};
    if (seg_left <= start && seg_right >= finish)
        return {tree[node][1], tree[node][0]};
    
    int mid = (start+finish)/2;
    pair<int ,int> temp_left = what_min_max(node*2, start, mid, seg_left, seg_right);
    pair<int ,int> temp_right = what_min_max(node*2+1, mid+1, finish, seg_left, seg_right);

    int total_min = (temp_left.first < temp_right.first) ? temp_left.first : temp_right.first;
    int total_max = (temp_left.second > temp_right.second) ? temp_left.second : temp_right.second;

    return {total_min, total_max};
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>arr[i];

    Init_tree(1,1,n);

    while (m--)
    {
        int a, b;
        cin>>a>>b;
        pair<int, int> temp = what_min_max(1, 1, n, a, b);
        cout<<temp.first<<" "<<temp.second<<"\n";
    }

    return 0;
}