// 22 / 1 / 3

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix;
int n, totalNum, answer;

void flood(int height)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((matrix[i][j] <= height) && (matrix[i][j] > 0))
            {
                totalNum--;
                matrix[i][j] = 0;
            }
        }
    }
}

void searchIsland(int r, int c)
{
    vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    matrix[r][c] *= 1000;
    for (int i = 0; i < 4; i++)
    {
        int r1 = r + d[i].first;
        int c1 = c + d[i].second;
        if ((r1 < 0) || (r1 >= n) || (c1 < 0) || (c1 >= n))
            continue;
        if ((matrix[r1][c1] > 0) && (matrix[r1][c1] <= 100))
            searchIsland(r1, c1);
    }
}

void checkIsland(void)
{
    int island = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((matrix[i][j] > 0) && (matrix[i][j] <= 100))
            {
                searchIsland(i, j);
                island++;
            }
        }
    }
    if (island > answer)
        answer = island;
}

void init(void)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] /= 1000;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    totalNum = n * n;
    matrix.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    for (int i = 0; true; i++)
    {
        flood(i);
        checkIsland();
        init();
        if (totalNum == 0)
            break;
    }

    cout << answer;

    return 0;
}