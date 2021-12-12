// 21 / 12 / 12

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

queue<vector<int>> bfsList;
vector<vector<int>> matrix;
vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
bool answer = false;
int r, c;

void bfs(int xR, int xC, int yR, int yC, int level)
{
    if (answer)
        return;

    if (level == 10)
        return;

    for (int i = 0; i < 4; i++)
    {
        int NXR = xR, NXC = xC, NYR = yR, NYC = yC;
        int redLife = 2, blueLife = 2;

        bool blueHole = false;

        while ((redLife > 0) || (blueLife > 0))
        {
            NXR += dir[i].first;
            NXC += dir[i].second;
            if (matrix[NXR][NXC] == 1)
            {
                answer = true;
            }
            else if ((matrix[NXR][NXC] == -1) || ((NXR == NYR) && (NXC == NYC)))
            {
                redLife--;
                NXR -= dir[i].first;
                NXC -= dir[i].second;
            }

            NYR += dir[i].first;
            NYC += dir[i].second;
            if (matrix[NYR][NYC] == 1)
            {
                blueHole = true;
                answer = false;
                break;
            }
            else if ((matrix[NYR][NYC] == -1) || ((NYR == NXR) && (NYC == NXC)))
            {
                blueLife--;
                NYR -= dir[i].first;
                NYC -= dir[i].second;
            }
        }

        if (blueHole)
            continue;

        if (answer)
        {
            cout << level + 1;
            return;
        }

        if ((NXR == xR) && (NXC == xC) && (NYR == yR) && (NYC == yC))
            continue;

        bfsList.push({NXR, NXC, NYR, NYC, level + 1});
    }
}

int main(void)
{
    cin >> r >> c;
    matrix.assign(r, vector<int>(c, 0));

    int redRow, redColumn, blueRow, blueColumn;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            if (s[j] == '#')
                matrix[i][j] = -1;
            else if (s[j] == 'O')
                matrix[i][j] = 1;
            else if (s[j] == 'R')
            {
                redRow = i;
                redColumn = j;
            }
            else if (s[j] == 'B')
            {
                blueRow = i;
                blueColumn = j;
            }
        }
    }

    bfsList.push({redRow, redColumn, blueRow, blueColumn, 0});

    while (!bfsList.empty())
    {
        if (answer)
            break;

        bfs(bfsList.front()[0], bfsList.front()[1], bfsList.front()[2],
            bfsList.front()[3], bfsList.front()[4]);
        bfsList.pop();
    }

    if (!answer)
        cout << -1;

    return 0;
}