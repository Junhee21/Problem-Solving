// 21/11/18

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int f, s, g, u, d;
vector<bool> check;
queue<pair<int, int>> q;

void solve()
{
    while (!q.empty())
    {
        int now = q.front().first;
        int buttons = q.front().second;
        if (now == g)
        {
            cout << buttons;
            return;
        }
        q.pop();
        if (now + u <= f && !check[now + u])
        {
            check[now + u] = true;
            q.push({now + u, buttons + 1});
        }
        if (now - d >= 1 && !check[now - d])
        {
            check[now - d] = true;
            q.push({now - d, buttons + 1});
        }
    }
    cout << "use the stairs";
}

int main(void)
{
    cin >> f >> s >> g >> u >> d;

    check.assign(f + 1, false);
    q.push({s, 0});
    check[s] = true;

    solve();
    return 0;
}