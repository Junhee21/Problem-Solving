// 21/10/24

#include <iostream>
using namespace std;

int answer, n, m;
int matrix[500][500];
bool check[500][500];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void Input(void)
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cin >> matrix[i][j];
    }
}

void DFS(int r, int c, int level, int num)
{
    if (level == 3)
    {
        if (num + matrix[r][c] > answer)
            answer = num + matrix[r][c];
        return;
    }
    
    check[r][c] = true;
    for (int i=0; i<4; i++)
    {
        if (r+dr[i]>=0 && r+dr[i]<n && c+dc[i]>=0 && c+dc[i]<m && !check[r+dr[i]][c+dc[i]])
            DFS(r+dr[i], c+dc[i], level+1, num+matrix[r][c]);
    }
    check[r][c] = false;
}

void Another(int r, int c)
{
    for (int i=0; i<4; i++)
    {
        int num = matrix[r][c];
        bool check = true;
        for (int j=0; j<4; j++)
        {
            if (i==j)
                continue;
            if (r+dr[j]<0 || r+dr[j]>=n || c+dc[j]<0 || c+dc[j]>=m)
            {
                check = false;
                break;
            }
            num += matrix[r+dr[j]][c+dc[j]];
        }
        if (num > answer && check)
            answer = num;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            DFS(i, j, 0, 0);
            Another(i, j);
        }
    }
    cout << answer;

    return 0;
}