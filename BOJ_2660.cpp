// 22 / 2 / 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int n;
vector<vector<int>> edge;
vector<pair<int, int>> arr;
vector<int> answerList;

int main(void)
{
    cin >> n;
    edge.assign(n + 1, vector<int>(n + 1, INF));

    while (true)
    {
        int x, y;
        cin >> x >> y;
        if ((x == -1) && (y == -1))
            break;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (edge[j][i] + edge[i][k] < edge[j][k])
                    edge[j][k] = edge[j][i] + edge[i][k];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int edgeMin = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (edge[i][j] > edgeMin)
                edgeMin = edge[i][j];
        }
        arr.push_back({edgeMin, i});
    }
    sort(arr.begin(), arr.end());

    int minSum = arr[0].first;
    int minNum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].first == minSum)
        {
            minNum++;
            answerList.push_back(arr[i].second);
        }
    }

    cout << minSum << " " << minNum << "\n";
    for (int i = 0; i < (int)answerList.size(); i++)
        cout << answerList[i] << " ";

    return 0;
}