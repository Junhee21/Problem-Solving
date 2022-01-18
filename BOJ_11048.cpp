// 22 / 1 / 17

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<int>> dp;
vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {-1, -1}};

int search(int r, int c)
{
    if ((r < 0) || (c < 0))
        return 0;
    if (dp[r][c] != -1)
        return dp[r][c];
    vector<int> arr;
    for (int i = 0; i < 3; i++)
        arr.push_back(search(r + dir[i].first, c + dir[i].second));
    return dp[r][c] = *max_element(arr.begin(), arr.end()) + matrix[r][c];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));
    dp.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    }

    cout << search(n - 1, m - 1);
    return 0;
}