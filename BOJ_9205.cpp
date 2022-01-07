// 22 / 1 / 7

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<vector<int>> edge;
vector<bool> check;
queue<int> q;

void input(void)
{
    cin >> n;
    arr.assign(n + 2, {0, 0});
    edge.assign(n + 2, vector<int>(0));
    check.assign(n + 2, false);

    for (int i = 0; i < n + 2; i++)
        cin >> arr[i].first >> arr[i].second;
}

int howLong(int node1, int node2)
{
    return (abs(arr[node1].first - arr[node2].first) +
            abs(arr[node1].second - arr[node2].second));
}

void init(void)
{
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = i + 1; j < n + 2; j++)
        {
            int distance = howLong(i, j);
            if (distance <= 1000)
            {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }
}

bool solve(void)
{
    while (!q.empty())
        q.pop();
    q.push(0);
    check[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        if (node == n + 1)
            return true;
        q.pop();
        for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
        {
            if (check[*iter])
                continue;
            q.push(*iter);
            check[*iter] = true;
        }
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        input();
        init();
        if (solve())
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;
}