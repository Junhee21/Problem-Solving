// 21/10/22

#include <iostream>
using namespace std;

int parent[1000+1];
int n, m;

int Find_parent(int node)
{
    if (parent[node] == node)
        return node;
    
    return parent[node] = Find_parent(parent[node]);
}

void Input(void)
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        parent[i] = i;

    while (m--)
    {
        int node1, node2;
        cin >> node1 >> node2;
        int parent1 = Find_parent(node1);
        int parent2 = Find_parent(node2);

        parent[parent2] = parent1;
    }
}

int Solve(void)
{
    for (int i=1; i<=n; i++)
        parent[i] = Find_parent(i);
    
    int answer = 0;
    for (int i=1; i<=n; i++)
    {
        if (parent[i] == i)
            answer++;
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    cout << Solve();
    
    return 0;
}