// 21/11/05

#include <iostream>
#include <vector>
using namespace std;

int n, answer;
vector<vector<int>> matrix;
vector<pair<int, int>> d = {{0, 1}, {1, 1}, {1, 0}};

void Solve(int r, int c, int state)
{
    if (r==n-1 && c==n-1)
    {
        answer++;
        return;
    }

    for (int i=0; i<3; i++)
    {
        int r_p = r+d[i].first;
        int c_p = c+d[i].second;
        if (r_p==n || c_p==n || matrix[r_p][c_p])
            continue;
        if (i==1 && (matrix[r+1][c] == 1 || matrix[r][c+1] == 1))
            continue;
        if (state==0 && i==2)
            continue;
        if (state==2 && i==0)
            continue;
        Solve(r_p, c_p, i);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    matrix.assign(n, vector<int>(n, 0));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin >> matrix[i][j];
    }

    Solve(0,1,0);
    cout << answer;
    return 0;
}