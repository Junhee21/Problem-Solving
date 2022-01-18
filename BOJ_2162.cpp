// 22 / 1 / 18

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> parent;
vector<int> groupHead;
vector<pair<int, int>> group;
vector<vector<int>> input;

int crossProduct(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int cp = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (cp > 0)
        return 1;
    else if (cp < 0)
        return -1;
    else
        return 0;
}

bool isGroup(int x, int y)
{
    int a1 = input[x][0], a2 = input[x][1], a3 = input[x][2], a4 = input[x][3];
    int b1 = input[y][0], b2 = input[y][1], b3 = input[y][2], b4 = input[y][3];
    int line1_line2_1 = crossProduct(a1, a2, b1, b2, b3, b4);
    int line1_line2_2 = crossProduct(a3, a4, b1, b2, b3, b4);
    int ccw1 = line1_line2_1 * line1_line2_2;

    int line2_line1_1 = crossProduct(b1, b2, a1, a2, a3, a4);
    int line2_line1_2 = crossProduct(b3, b4, a1, a2, a3, a4);
    int ccw2 = line2_line1_1 * line2_line1_2;

    if (ccw1 + ccw2 < 0)
        return true;
    if ((ccw1 == 0) && (ccw2 == 0))
    {
        int p = a1;
        if ((a3 == p) && (b1 == p) && (b3 == p))
        {
            if (((a2 - b2) * (a2 - b4) <= 0) || ((a4 - b2) * (a4 - b4) <= 0))
                return true;
            if (((b2 - a2) * (b2 - a4) <= 0) || ((b4 - a2) * (b4 - a4) <= 0))
                return true;
            else
                return false;
        }
        if (((a1 - b1) * (a1 - b3) <= 0) || ((a3 - b1) * (a3 - b3) <= 0))
            return true;
        if (((b1 - a1) * (b1 - a3) <= 0) || ((b3 - a1) * (b3 - a3) <= 0))
            return true;
        else
            return false;
    }
    return false;
}

int searchParent(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = searchParent(parent[node]);
}

void unionGroup(int x, int y)
{
    int parent_x = searchParent(x);
    int parent_y = searchParent(y);

    if (parent_x == parent_y)
        return;
    parent[parent_y] = parent_x;
}

void solve(void)
{
    for (int i = 0; i < n; i++)
        groupHead[searchParent(i)]++;

    int maxGroup = 0;
    int numGroup = 0;
    for (int i = 0; i < n; i++)
    {
        int num = groupHead[i];
        if (num > 0)
        {
            numGroup++;
            if (num > maxGroup)
                maxGroup = num;
        }
    }
    cout << numGroup << "\n"
         << maxGroup;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    parent.assign(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    groupHead.assign(n, 0);
    input.assign(n, vector<int>(4, 0));

    for (int i = 0; i < n; i++)
        cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isGroup(i, j))
                group.push_back({i, j});
        }
    }

    for (auto i = group.begin(); i != group.end(); i++)
        unionGroup((*i).first, (*i).second);

    solve();
    return 0;
}