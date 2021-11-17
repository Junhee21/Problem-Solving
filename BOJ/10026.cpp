// 21/10/19

#include <iostream>
#include <string>
using namespace std;

bool color_weak[100][100];
bool non_color_weak[100][100];
int matrix[100][100];
int r_dx[4] = {1, 0 ,-1, 0};
int c_dx[4] = {0, 1, 0 ,-1};
int n;

void Search_matrix_non(int r, int c, int color)
{
    non_color_weak[r][c] = true;
    for (int i=0; i<4; i++)
    {
        int new_r = r+r_dx[i];
        int new_c = c+c_dx[i];
        if (new_r<n && new_r>=0 && new_c<n && new_c>=0
            && matrix[new_r][new_c]==color && !non_color_weak[new_r][new_c])
        {
            Search_matrix_non(new_r, new_c, color);
        }
    }
}

void Search_matrix_weak(int r, int c, int color)
{
    color_weak[r][c] = true;
    for (int i=0; i<4; i++)
    {
        int new_r = r+r_dx[i];
        int new_c = c+c_dx[i];
        if (new_r<n && new_r>=0 && new_c<n && new_c>=0 && matrix[new_r][new_c] && !color_weak[new_r][new_c])
        {
            if (color == 1 && matrix[new_r][new_c]==1)
                Search_matrix_weak(new_r, new_c, color);
            if (color > 1 && matrix[new_r][new_c] > 1)
                Search_matrix_weak(new_r, new_c, color);
        }
    }
}

int result_non(void)
{
    int answer = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (non_color_weak[i][j])
                continue;
            else
            {
                Search_matrix_non(i, j, matrix[i][j]);
                answer ++;
            }
        }
    }
    return answer;
}

int result_weak(void)
{
    int answer = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (color_weak[i][j])
                continue;
            else
            {
                Search_matrix_weak(i, j, matrix[i][j]);
                answer ++;
            }
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
    {
        string s;
        cin >>s;
        for (int j=0; j<n; j++)
        {
            if (s[j]=='B')
                matrix[i][j] = 1;
            else if (s[j]=='R')
                matrix[i][j] = 2;
            else
                matrix[i][j] = 3;
        }
    }

    cout << result_non()<< " " << result_weak();
    return 0;
}
