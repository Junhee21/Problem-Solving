// 21/10/27

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[8];
bool check[8];

void DFS(vector<int>&v, int level)
{
    if (level == m)
    {
        for (int i=0; i<m; i++)
        {
            cout << v[i] <<" ";
        }
        cout << "\n";
        return;
    }
    for (int i=0; i<n; i++)
    {
        if (check[i])
        {
            continue;
        }
        check[i] = true;
        v.push_back(arr[i]);
        DFS(v, level+1);
        check[i] = false;
        v.pop_back();
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    vector<int> v;
    DFS(v, 0);
    return 0;
}