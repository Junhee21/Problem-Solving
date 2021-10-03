//21 10 04

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, k, t;
bool visited[3001];
queue<pair<int, int>> q;

void bfs(void)
{
    if (q.empty())
    {
        cout<<-1;
        return;
    }
    if (q.front().first == n)
    {
        cout<<q.front().second;
        return;
    }

    int x = q.front().first;
    for (int i=0; i<=k; i++)
    {
        if (x+(2*i)-k < 0 ||x+(2*i)-k > n || visited[x+(2*i)-k])
            continue;
        if (x<(k-i) || n-x<i)
            continue;
        visited[x+(2*i)-k] = true;
        q.push({x+(2*i)-k, q.front().second+1});
    }
    q.pop();
    bfs();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    string T = "T";
    cin>>n>>k>>s;
    for (auto iter=s.begin(); iter!=s.end(); iter++)
    {
        if (*iter == T[0])
            t++;
    }

    visited[t] = true;
    q.push({t,0});

    bfs();
    return 0;
}