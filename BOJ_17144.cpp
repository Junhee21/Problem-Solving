// 21/11/06

#include <iostream>
#include <vector>
using namespace std;

int n, m, t, total;
int ccw_r, ccw_c, cw_r, cw_c;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> spread(vector<vector<int>> matrix)
{
    vector<vector<int>> output(n, vector<int>(m, 0));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int dust = matrix[i][j]/5;
            output[i][j] += matrix[i][j];
            for (int k=0; k<4; k++)
            {
                int r1 = i+d[k].first;
                int c1 = j+d[k].second;
                if (r1<0||r1>=n||c1<0||c1>=m||matrix[r1][c1]==-1)
                    continue;
                output[r1][c1] += dust;
                output[i][j] -= dust;
            }
        }
    }
    return output;
}

vector<vector<int>> clean(vector<vector<int>> matrix)
{
    vector<vector<int>> output;
    output.assign(matrix.begin(), matrix.end());

    vector<pair<int, int>> d_ccw = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int r = ccw_r;
    int c = ccw_c;
    int dir = 0;
    while (1)
    {
        if ((dir==0&&r==0)||(dir==1&&c==m-1)||(dir==2&&r==ccw_r))
            dir++;
        int r1 = r+d_ccw[dir].first;
        int c1 = c+d_ccw[dir].second;
        if (r1 == ccw_r && c1 == ccw_c)
            break;
        output[r][c] = matrix[r1][c1];
        r = r1;
        c= c1;
    }
    vector<pair<int, int>> d_cw = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    r = cw_r;
    c = cw_c;
    dir = 0;
    while (1)
    {
        if ((dir==0&&r==n-1)||(dir==1&&c==m-1)||(dir==2&&r==cw_r))
            dir++;
        int r1 = r+d_cw[dir].first;
        int c1 = c+d_cw[dir].second;
        if (r1 == cw_r && c1 == cw_c)
            break;
        output[r][c] = matrix[r1][c1];
        r = r1;
        c= c1;
    }

    total -= (output[ccw_r][ccw_c]+output[cw_r][cw_c]);
    output[ccw_r][ccw_c] = output[cw_r][cw_c] = -1;
    output[ccw_r][ccw_c+1] = output[cw_r][cw_c+1] = 0;

    return output;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    bool ccw = true;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int x;
            cin >> x;
            matrix[i][j] = x;
            if (x>0)
                total+=x;
            if (x==-1)
            {
                if (ccw)
                {
                    ccw_r = i;
                    ccw_c = j;
                    ccw = false;
                }
                else
                {
                    cw_r = i;
                    cw_c = j;
                }
            }
        }
    }

    while (t--)
    {
        matrix = spread(matrix);
        matrix = clean(matrix);
    }

    cout << total;
    return 0;
}