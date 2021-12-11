// 21 / 12 / 11

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> arr(1000000, 0);
vector<bool> check(1000000, false);
vector<vector<int>> matrix;
vector<vector<int>> answer;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int r, c;

void initSize(int a, int b, int n)
{
    matrix[a][b] = n;
    arr[n]++;

    for (int i = 0; i < 4; i++)
    {
        int a1 = a + dir[i].first;
        int b1 = b + dir[i].second;

        if ((a1 < r) && (a1 >= 0) && (b1 < c) && (b1 >= 0) && (matrix[a1][b1] == 0))
            initSize(a1, b1, n);
    }
}

void coutSize(int a, int b)
{
    vector<int> numCheck;
    int totalSize = 1;
    for (int i = 0; i < 4; i++)
    {
        int a1 = a + dir[i].first;
        int b1 = b + dir[i].second;

        if ((a1 < r) && (a1 >= 0) && (b1 < c) && (b1 >= 0))
        {
            int n = matrix[a1][b1];
            if ((n > 1) && (!check[n]))
            {
                totalSize += arr[n];
                check[n] = true;
                numCheck.push_back(n);
            }
        }
    }

    for (auto iter = numCheck.begin(); iter != numCheck.end(); iter++)
        check[*iter] = false;
    answer[a][b] = totalSize % 10;
}

int main(void)
{
    cin >> r >> c;
    matrix.assign(r, vector<int>(c, 0));
    answer.assign(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = c - 1; j >= 0; j--)
        {
            matrix[i][j] = s[j] - '0';
            answer[i][j] = s[j] - '0';
        }
    }

    int num = 2;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
                initSize(i, j, num++);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 1)
                coutSize(i, j);
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << answer[i][j];
        cout << "\n";
    }

    return 0;
}