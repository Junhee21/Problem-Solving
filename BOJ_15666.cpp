// 21/11/10

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> s;
int n, m;

void DFS(int level, vector<int>&arr)
{
    if (level == m)
    {
        for (int i=0; i<(int)arr.size(); i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (auto iter=s.begin(); iter!=s.end(); iter++)
    {
        if (!arr.empty() && *iter < arr.back())
            continue;
        arr.push_back(*iter);
        DFS(level+1, arr);
        arr.pop_back();
    }
}

int main(void)
{
    cin >> n >> m;
    while (n--)
    {
        int x;
        cin >> x;
        if (!s.count(x))
            s.insert(x);
    }

    vector<int> arr;
    DFS(0, arr);
        
    return 0;
}