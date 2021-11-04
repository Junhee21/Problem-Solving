// 21/11/04

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> edge_up;
vector<vector<int>> edge_down;

void Input(void)
{
    cin >> n >> m;
    edge_up.assign(n+1, vector<int>(0,0));
    edge_down.assign(n+1, vector<int>(0,0));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edge_down[a].push_back(b);
        edge_up[b].push_back(a);
    }
}


void Search_up(int i, vector<bool>&check)
{
    for (auto iter = edge_up[i].begin(); iter!=edge_up[i].end(); iter++)
    {
        if (check[*iter])
            continue;
        check[*iter] = true;
        Search_up(*iter, check);
    }
}

void Search_down(int i, vector<bool>&check)
{
    for (auto iter = edge_down[i].begin(); iter!=edge_down[i].end(); iter++)
    {
        if (check[*iter])
            continue;
        check[*iter] = true;
        Search_down(*iter, check);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    for (int i=1; i<=n; i++)
    {
        vector<bool> check(n+1, false);
        Search_up(i, check);
        Search_down(i, check);

        int answer = 0;
        for (int j=1; j<=n; j++)
        {
            if (!check[j])
                answer++;
        }
        cout << answer-1 <<"\n";
    }

    return 0;
}