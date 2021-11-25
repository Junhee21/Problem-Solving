// 21/11/25

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> parent;
vector<vector<int>> edge;
vector<int> answer;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    parent.assign(n + 1, 0);
    edge.assign(n + 1, vector<int>(0));
    while (m--)
    {
        int num;
        cin >> num;
        int p = 0, c = 0;
        while (num--)
        {
            cin >> c;
            if (p != 0)
            {
                edge[p].push_back(c);
                parent[c]++;
            }
            p = c;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        answer.push_back(x);

        for (auto iter = edge[x].begin(); iter != edge[x].end(); iter++)
        {
            parent[(*iter)]--;
            if (parent[*(iter)] == 0)
                q.push(*iter);
        }
    }

    if (answer.size() == n)
    {
        for (int i = 0; i < n; i++)
            cout << answer[i] << "\n";
    }
    else
        cout << 0;
    return 0;
}