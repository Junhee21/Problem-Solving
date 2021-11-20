// 21/11/20

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> check(26, false);
vector<vector<int>> matrix(20, vector<int>(20, -1));
vector<pair<int, int>> d = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, answer;

void DFS(int r, int c, int length)
{
    if (length > answer)
        answer = length;
    for (int i = 0; i < 4; i++)
    {
        int r1 = r + d[i].first;
        int c1 = c + d[i].second;
        if (r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && !check[matrix[r1][c1]])
        {
            check[matrix[r1][c1]] = true;
            DFS(r1, c1, length + 1);
            check[matrix[r1][c1]] = false;
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = str[j] - 'A';
        }
    }

    check[matrix[0][0]] = true;
    DFS(0, 0, 1);

    cout << answer;
    return 0;
}