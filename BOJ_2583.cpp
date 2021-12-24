// 21 / 12 / 24

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> matrix;
vector<int> arr;
int n, m, k;

void solve(int x, int y, int *ptr)
{
    matrix[x][y] = 1;
    (*ptr)++;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + d[i].first;
        int y1 = y + d[i].second;
        if ((x1 >= 0) && (x1 < n) && (y1 >= 0) && (y1 < m) && (matrix[x1][y1] == 0))
            solve(x1, y1, ptr);
    }
}

int main(void)
{
    cin >> m >> n >> k;
    matrix.assign(n, vector<int>(m, 0));

    while (k--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < c; i++)
        {
            for (int j = b; j < d; j++)
                matrix[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                int num = 0;
                solve(i, j, &num);
                arr.push_back(num);
            }
        }
    }

    sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for (int i = 0; i < (int)arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}