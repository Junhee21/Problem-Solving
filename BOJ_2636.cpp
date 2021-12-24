// 21 / 12 / 24

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, leftCheese;

void searchAir(int x, int y, int level)
{
    matrix[x][y] = level;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + d[i].first;
        int y1 = y + d[i].second;
        if ((x1 >= 0) && (x1 < n) && (y1 >= 0) && (y1 < m) && (matrix[x1][y1] != 1) && (matrix[x1][y1] < level))
            searchAir(x1, y1, level);
    }
}

int meltCheese(int level)
{
    int thisTimeCheese = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (matrix[i + d[k].first][j + d[k].second] == level)
                    {
                        matrix[i][j] = 0;
                        thisTimeCheese++;
                        break;
                    }
                }
            }
        }
    }
    return thisTimeCheese;
}

int main(void)
{
    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
                leftCheese++;
        }
    }

    for (int i = 1; true; i++)
    {
        searchAir(0, 0, i + 1);
        int x = meltCheese(i + 1);
        if (x == leftCheese)
        {
            cout << i << "\n";
            cout << leftCheese;
            break;
        }
        leftCheese -= x;
    }

    return 0;
}