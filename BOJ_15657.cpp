// 21/11/04

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n, m;

void DFS(int level, int num, vector<int>&h)
{
    if (level == m)
    {
        for (int i=0; i<m; i++)
            cout << h[i] <<" ";
        cout << "\n";
        return;
    }

    for (int i=num; i<n; i++)
    {
        h.push_back(arr[i]);
        DFS(level+1, i, h);
        h.pop_back();
    }
}

int main(void)
{
    cin >> n >> m;

    arr.assign(n, 0);
    for (int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> h;
    DFS(0, 0, h);

    return 0;
}