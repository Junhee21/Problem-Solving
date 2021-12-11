// 21 / 12 / 11

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> groupMatrix;
vector<pair<int, int>> dir = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> parent(1000001, 0);
int r, c;

void solve(int a, int b, int num)
{
    groupMatrix[a][b] = num;

    int a1 = dir[matrix[a][b]].first + a;
    int b1 = dir[matrix[a][b]].second + b;

    if ((a1 < 0) || (a1 >= r) || (b1 < 0) || (b1 >= c))
    {
        parent[num] = num;
        return;
    }
    if (groupMatrix[a1][b1] == num)
    {
        parent[num] = num;
        return;
    }
    if (groupMatrix[a1][b1] == 0)
    {
        solve(a1, b1, num);
        return;
    }

    parent[num] = parent[groupMatrix[a1][b1]];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    matrix.assign(r, vector<int>(c, 0));
    groupMatrix.assign(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            if (s[j] == 'U')
                matrix[i][j] = 1;
            else if (s[j] == 'D')
                matrix[i][j] = 2;
            else if (s[j] == 'L')
                matrix[i][j] = 3;
            else
                matrix[i][j] = 4;
        }
    }

    int num = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (groupMatrix[i][j] == 0)
            {
                solve(i, j, num++);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < 1000001; i++)
    {
        if (parent[i] == i)
            answer++;
    }

    cout << answer;

    return 0;
}