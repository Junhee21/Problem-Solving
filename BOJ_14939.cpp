// 21 / 12 / 29

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int answer = 101;
vector<vector<bool>> bulb(11, vector<bool>(12, false));

void turnOff(int level, int click)
{
    if (level == 10)
    {
        bool allOff = true;
        for (int i = 1; i < 11; i++)
        {
            if (bulb[9][i])
            {
                allOff = false;
                break;
            }
        }

        if (allOff)
        {
            if (click < answer)
                answer = click;
        }
        return;
    }

    int bit1 = 0;
    int bit2 = 0;
    for (int i = 1; i < 11; i++)
    {
        if (bulb[level][i])
            bit1 += (1 << i);
        if (bulb[level + 1][i])
            bit2 += (1 << i);
    }

    for (int i = 1; i < 11; i++)
    {
        if (bulb[level - 1][i])
        {
            click++;
            for (int j = -1; j <= 1; j++)
                bulb[level][i + j] = !bulb[level][i + j];
            bulb[level + 1][i] = !bulb[level + 1][i];
        }
    }

    turnOff(level + 1, click);

    for (int i = 1; i < 11; i++)
    {
        if (bit1 & (1 << i))
            bulb[level][i] = true;
        else
            bulb[level][i] = false;
        if (bit2 & (1 << i))
            bulb[level + 1][i] = true;
        else
            bulb[level + 1][i] = false;
    }
}

void dfs(int i, int click)
{
    if (i == 11)
    {
        turnOff(1, click);
        return;
    }

    for (int j = -1; j <= 1; j++)
        bulb[0][i + j] = !bulb[0][i + j];
    bulb[1][i] = !bulb[1][i];
    dfs(i + 1, click + 1);

    for (int j = -1; j <= 1; j++)
        bulb[0][i + j] = !bulb[0][i + j];
    bulb[1][i] = !bulb[1][i];
    dfs(i + 1, click);
}

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++)
        {
            if (str[j] == 'O')
                bulb[i][j + 1] = true;
        }
    }

    dfs(1, 0);

    if (answer < 101)
        cout << answer;
    else
        cout << -1;

    return 0;
}