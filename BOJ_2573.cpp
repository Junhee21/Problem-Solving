// 22 / 1 / 7

#include <iostream>
#include <vector>
using namespace std;

int n, m, totalNum, nowNum;
vector<vector<int>> matrix;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void melt(void)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] > 0)
            {
                int num = 0;
                for (int k = 0; k < 4; k++)
                {
                    int i1 = i + dir[k].first;
                    int j1 = j + dir[k].second;
                    if ((i1 >= 0) && (i1 < n) && (j1 >= 0) && (j1 < m) && (matrix[i1][j1] == 0))
                        num++;
                }
                if (matrix[i][j] <= num)
                {
                    matrix[i][j] = -1;
                    totalNum--;
                }
                else
                    matrix[i][j] -= num;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

void search(int i, int j)
{
    nowNum++;
    matrix[i][j] *= -1;
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dir[k].first;
        int j1 = j + dir[k].second;
        if ((i1 >= 0) && (i1 < n) && (j1 >= 0) && (j1 < m) && (matrix[i1][j1] > 0))
            search(i1, j1);
    }
}

bool isDivided(void)
{
    nowNum = 0;
    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (check)
            break;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] > 0)
            {
                search(i, j);
                check = true;
                break;
            }
        }
    }
    if (nowNum < totalNum)
        return true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] < 0)
                matrix[i][j] *= -1;
        }
    }
    return false;
}

int solve(void)
{
    for (int i = 1; totalNum>0; i++)
    {
        melt();
        bool b = isDivided();
        if (b)
            return i;
    }
    return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] > 0)
                totalNum++;
        }
    }
    cout << solve();
    return 0;
}