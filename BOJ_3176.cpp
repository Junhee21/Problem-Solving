// 21/11/16

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
const int maxDepth = 17;
const int initNum = 100000 + 1;
const long long temp = 100000000001;
vector<bool> check(initNum, false);
vector<int> depth(initNum, 0);
vector<pair<int, int>> edge[initNum];
vector<vector<pair<int, pair<long long, long long>>>> parent(initNum,
    vector<pair<int, pair<long long, long long>>>(maxDepth));

void searchDepth(int node, int level)
{
    check[node] = true;
    depth[node] = level;
    for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
    {
        if (check[(*iter).first])
            continue;
        parent[(*iter).first][0] = {node, {(*iter).second, (*iter).second}};
        searchDepth((*iter).first, level + 1);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    searchDepth(1, 0);

    for (int i = 1; i < maxDepth; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int parentNode = parent[j][i - 1].first;
            parent[j][i].first = parent[parentNode][i - 1].first;
            if (parent[j][i - 1].second.first > parent[parentNode][i - 1].second.first)
                parent[j][i].second.first = parent[j][i - 1].second.first;
            else
                parent[j][i].second.first = parent[parentNode][i - 1].second.first;
            if (parent[j][i - 1].second.second < parent[parentNode][i - 1].second.second)
                parent[j][i].second.second = parent[j][i - 1].second.second;
            else
                parent[j][i].second.second = parent[parentNode][i - 1].second.second;
        }
    }

    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (depth[x] > depth[y])
            swap(x, y);

        int depthGap = depth[y] - depth[x];
        int step = 0;
        long long maxX = 0;
        long long maxY = 0;
        long long minX = temp;
        long long minY = temp;

        while (depthGap != 0)
        {
            if (depthGap % 2 == 1)
            {
                if (parent[y][step].second.first > maxY)
                {
                    maxY = parent[y][step].second.first;
                }
                if (parent[y][step].second.second < minY)
                    minY = parent[y][step].second.second;
                y = parent[y][step].first;
            }
            if (depthGap == 1)
                break;
            step++;
            depthGap /= 2;
        }

        if (x == y)
        {
            cout << minY << " " << maxY << "\n";
        }

        else
        {
            for (int i = maxDepth - 1; i >= 0; i--)
            {
                if (parent[x][i].first != parent[y][i].first)
                {
                    if (parent[y][i].second.first > maxY)
                        maxY = parent[y][i].second.first;
                    if (parent[y][i].second.second < minY)
                        minY = parent[y][i].second.second;
                    y = parent[y][i].first;
                    if (parent[x][i].second.first > maxX)
                        maxX = parent[x][i].second.first;
                    if (parent[x][i].second.second < minX)
                        minX = parent[x][i].second.second;
                    x = parent[x][i].first;
                }
            }

            vector<long long> maxArr = {maxX, maxY, parent[x][0].second.first, parent[y][0].second.first};
            vector<long long> minArr = {minX, minY, parent[x][0].second.second, parent[y][0].second.second};
            sort(maxArr.begin(), maxArr.end());
            sort(minArr.begin(), minArr.end());
            cout << minArr[0] << " " << maxArr[3] << "\n";
        }
    }
    return 0;
}