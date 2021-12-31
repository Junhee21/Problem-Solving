// 21 / 12 / 31

#include <iostream>
#include <vector>
using namespace std;

int g, p, answer;
vector<int> parent;
vector<int> plane;

int whoParent(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = whoParent(parent[node]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> g >> p;
    parent.assign(g + 1, 0);
    plane.assign(p, 0);
    for (int i = 1; i <= g; i++)
        parent[i] = i;
    for (int i = 0; i < p; i++)
        cin >> plane[i];

    for (int i = 0; i < p; i++)
    {
        int x = whoParent(plane[i]);
        if (whoParent(x) == 0)
            break;
        answer++;
        parent[x] = parent[x - 1];
    }

    cout << answer;
    return 0;
}