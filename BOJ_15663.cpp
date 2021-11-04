// 21/11/05

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> check;
vector<int> arr;
int n, m;

void DFS(int level, vector<int>&answer)
{
    if (level == m)
    {
        for (int i=0; i<m; i++)
        {
            cout << answer[i] <<" ";
        }
        cout << "\n";
        return;
    }

    int last = 0;
    for (int i=0; i<n; i++)
    {
        if (check[i] || arr[i]==last)
            continue;
        last = arr[i];
        check[i] = true;
        answer.push_back(arr[i]);
        DFS(level+1, answer);
        check[i] = false;
        answer.pop_back();
    }
}

int main(void)
{
    cin >> n >> m;

    check.assign(n, false);
    arr.assign(n, 0);
    for (int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    vector<int> answer;
    DFS(0, answer);
    return 0;
}