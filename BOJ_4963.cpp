// 22 / 1 / 1

#include <iostream>
#include <vector>
using namespace std;

int w, h;
vector<vector<int>> matrix;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},
                            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void input(void)
{
    matrix.assign(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> matrix[i][j];
    }
}

void searchIsland(int r, int c)
{
    matrix[r][c] = 0;
    for (int i = 0; i < 8; i++)
    {
        int r1 = r + d[i].first;
        int c1 = c + d[i].second;
        if ((r1 >= 0) && (r1 < h) && (c1 >= 0) && (c1 < w) && (matrix[r1][c1] == 1))
            searchIsland(r1, c1);
    }
}

int solve(void)
{
    int answer = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (matrix[i][j] == 1)
            {
                answer++;
                searchIsland(i, j);
            }
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> w >> h;
        if ((w == 0) && (h == 0))
            break;
        input();
        cout << solve() << "\n";
    }
    return 0;
}
