// 22 / 1 / 15

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
string str;
vector<vector<int>> edge;
vector<bool> check;

void init(void)
{
    for (int i = 1; i <= str.size(); i++)
    {
        for (int j = 0; j <= str.size() - i; j++)
        {
            bool check = true;
            for (int k = 0; true; k++)
            {
                if (j + k > j + i - k - 1)
                    break;
                if (str[j + k] != str[j + i - k - 1])
                {
                    check = false;
                    break;
                }
            }
            if (check)
                edge[j].push_back(j + i);
        }
    }
}

void solve(void)
{
    q.push({0, 0});
    while (true)
    {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (node == str.size())
        {
            cout << level;
            break;
        }
        if (check[node])
            continue;
        check[node] = true;
        for (auto i = edge[node].begin(); i != edge[node].end(); i++)
            q.push({*i, level + 1});
    }
}

int main(void)
{
    cin >> str;
    edge.assign(str.size(), vector<int>(0, 0));
    check.assign(str.size(), false);
    init();
    solve();
    return 0;
}