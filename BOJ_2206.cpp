// 22 / 1 / 18

// bool로 방문여부를 체크한 경우 (코드가 훨씬 간단)
// 이미 방문한 경우 이미 최솟값이 아니므로 dp로 step을 체크할 필요없이 bool로 방문여부만 체크하면 된다.
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<vector<bool>>> check;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue<vector<int>> q;

int search(void)
{
    q.push({0, 0, 0, 1});
    check[0][0][0] = true;
    while (!q.empty())
    {
        int r = q.front()[0], c = q.front()[1], state = q.front()[2], step = q.front()[3];
        q.pop();
        if ((r == n - 1) && (c == m - 1))
            return step;

        for (int i = 0; i < 4; i++)
        {
            int r1 = r + dir[i].first;
            int c1 = c + dir[i].second;
            if ((r1 < 0) || (r1 >= n) || (c1 < 0) || (c1 >= m) || (check[r1][c1][state]))
                continue;

            if (matrix[r1][c1] == 0)
            {
                check[r1][c1][state] = true;
                q.push({r1, c1, state, step + 1});
            }
            if ((state == 0) && (matrix[r1][c1] == 1))
            {
                check[r1][c1][1] = true;
                q.push({r1, c1, 1, step + 1});
            }
        }
    }
    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    matrix.assign(n, vector<int>(m, 0));
    check.assign(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            matrix[i][j] = str[j] - '0';
    }

    cout << search();
    return 0;
}

// 일일이 dp로 값을 체크한 경우
// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>
// using namespace std;

// const int INF = 987654321;
// int n, m;
// vector<vector<int>> matrix;
// vector<vector<vector<int>>> dp; // 벽 안부심, 한번이미부심
// vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// queue<vector<int>> q;

// int search(void)
// {
//     while (!q.empty())
//     {
//         int r = q.front()[0], c = q.front()[1], state = q.front()[2], step = q.front()[3];
//         q.pop();
//         if ((r == n - 1) && (c == m - 1))
//             return step;

//         for (int i = 0; i < 4; i++)
//         {
//             int r1 = r + dir[i].first;
//             int c1 = c + dir[i].second;
//             if ((r1 < 0) || (r1 >= n) || (c1 < 0) || (c1 >= m))
//                 continue;

//             if ((matrix[r1][c1] == 0) && (dp[r1][c1][state] > step + 1))
//             {
//                 dp[r1][c1][state] = step + 1;
//                 q.push({r1, c1, state, step + 1});
//             }
//             if ((state == 0) && (matrix[r1][c1] == 1) && (dp[r1][c1][1] > step + 1))
//             {
//                 dp[r1][c1][1] = step + 1;
//                 q.push({r1, c1, 1, step + 1});
//             }
//         }
//     }
//     return -1;
// }

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> m;
//     matrix.assign(n, vector<int>(m, 0));
//     dp.assign(n, vector<vector<int>>(m, vector<int>(2, INF)));
//     for (int i = 0; i < n; i++)
//     {
//         string str;
//         cin >> str;
//         for (int j = 0; j < m; j++)
//             matrix[i][j] = str[j] - '0';
//     }

//     q.push({0, 0, 0, 1});
//     cout << search();
//     return 0;
// }