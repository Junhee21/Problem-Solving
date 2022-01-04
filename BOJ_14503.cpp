// 22 / 1 / 4

#include <iostream>
#include <vector>
using namespace std;

int n, m, answer;
vector<vector<int>> matrix;
vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void clean(int r, int c, int dir)
{
    if (matrix[r][c] == 0)
    {
        matrix[r][c] = 2;
        answer++;
    }
    for (int i = 0; i < 4; i++)
    {
        dir--;
        if (dir < 0)
            dir = 3;
        int r1 = r + direction[dir].first;
        int c1 = c + direction[dir].second;
        if (matrix[r1][c1] == 0)
        {
            clean(r1, c1, dir);
            return;
        }
    }
    int r1 = r + (-1) * direction[dir].first;
    int c1 = c + (-1) * direction[dir].second;
    if (matrix[r1][c1] == 2)
        clean(r1, c1, dir);
}

int main(void)
{
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    matrix.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    clean(a, b, c);
    cout << answer;
    return 0;
}