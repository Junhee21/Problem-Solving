// 21 / 12 / 11

#include <iostream>
#include <vector>
using namespace std;

int r, c, shark, answer;
vector<vector<int>> matrix;
vector<vector<int>> arr; // isEaten, r, c, velocity, dir, size
vector<pair<int, int>> dir = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void input(void)
{
    cin >> r >> c >> shark;
    matrix.assign(r + 1, vector<int>(c + 1, 0));
    arr.assign(shark + 1, vector<int>(6, 0));
    for (int i = 1; i <= shark; i++)
    {
        arr[i][0] = 1;
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4] >> arr[i][5];
        matrix[arr[i][1]][arr[i][2]] = i;
    }
}

void moveShark(int num)
{
    matrix[arr[num][1]][arr[num][2]] = 0;
    int disR = (((dir[arr[num][4]].first) * arr[num][3])) % ((r - 1) * 2);
    int disC = (((dir[arr[num][4]].second) * arr[num][3])) % ((c - 1) * 2);
    int newR = disR + arr[num][1];
    int newC = disC + arr[num][2];

    while ((newR <= 0) || (newR > r) || (newC <= 0) || (newC > c))
    {
        if (newR <= 0)
        {
            newR = -newR + 2;
            arr[num][4] = 2;
        }
        else if (newC <= 0)
        {
            newC = -newC + 2;
            arr[num][4] = 3;
        }
        else if (newR > r)
        {
            newR = 2 * r - newR;
            arr[num][4] = 1;
        }
        else
        {
            newC = 2 * c - newC;
            arr[num][4] = 4;
        }
    }

    arr[num][1] = newR;
    arr[num][2] = newC;
}

void check(void)
{
    for (int i = 1; i <= shark; i++)
    {
        if (arr[i][0] == 0)
            continue;
        if (matrix[arr[i][1]][arr[i][2]] == 0)
            matrix[arr[i][1]][arr[i][2]] = i;
        else
        {
            if (arr[matrix[arr[i][1]][arr[i][2]]][5] < arr[i][5])
            {
                arr[matrix[arr[i][1]][arr[i][2]]][0] = 0;
                matrix[arr[i][1]][arr[i][2]] = i;
            }
            else
            {
                arr[i][0] = 0;
            }
        }
    }
}

void action(int n)
{
    for (int i = 1; i <= r; i++)
    {
        if (matrix[i][n])
        {
            answer += arr[matrix[i][n]][5];
            arr[matrix[i][n]][0] = 0;
            matrix[i][n] = 0;
            break;
        }
    }

    for (int i = 1; i <= shark; i++)
    {
        if (arr[i][0])
            moveShark(i);
    }

    check();
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    for (int i = 1; i <= c; i++)
    {
        action(i);
    }
    cout << answer;
    return 0;
}