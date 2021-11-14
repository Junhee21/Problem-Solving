// 21/11/14

#include <iostream>
#include <vector>
using namespace std;

int n, m, answer;
vector<vector<int>> matrix;
vector<pair<int, int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void virus(vector<vector<int>> &matrix, int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        int r1 = r + d[i].first;
        int c1 = c + d[i].second;
        if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && matrix[r1][c1] == 0)
        {
            matrix[r1][c1] = 2;
            virus(matrix, r1, c1);
        }
    }
}

void solve(vector<vector<int>> matrix)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 2)
            {
                virus(matrix, i, j);
            }
        }
    }

    int nowAnswer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                nowAnswer++;
            }
        }
    }

    if (nowAnswer > answer)
        answer = nowAnswer;
}

void DFS(int level, int limit)
{
    if (level == 3)
    {
        solve(matrix);
        return;
    }

    for (int i = limit; i < n * m; i++)
    {
        int n1 = i / m;
        int m1 = i % m;

        if (matrix[n1][m1] > 0)
            continue;
        matrix[n1][m1] = 1;
        DFS(level + 1, i + 1);
        matrix[n1][m1] = 0;
    }
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
        }
    }

    DFS(0, 0);

    cout << answer;

    return 0;
}