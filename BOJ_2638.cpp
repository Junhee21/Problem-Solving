// 21/11/02

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> cheese;
vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int n, m;

void Search_air(int r, int c)
{
    cheese[r][c] = 2;
    for (int i=0; i<4; i++)
    {
        int r1 = r+(d[i].first);
        int c1 = c+(d[i].second);
        if (r1>=0 && r1<=n && c1 >=0 && c1<m && cheese[r1][c1] == 0)
            Search_air(r1, c1);
    }
}

bool Solve(void)
{
    Search_air(0, 0);
    vector<pair<int, int>> melt;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (cheese[i][j] != 1)      
                continue;

            int check = 0;
            for (int k=0; k<4; k++)
            {
                int i1 = i+d[k].first;
                int j1 = j+d[k].second;
                if (i1<1 || i1>n || j1<0 || j1 >=m || cheese[i1][j1] == 2)
                    check++;
            }
            if (check>=2)
                melt.push_back({i, j});
        }
    }
    if (melt.empty())
        return false;


    for (int i=0; i<=n; i++)
    {
        for (int j=1; j<m; j++)
        {
            if (cheese[i][j] == 2)
                cheese[i][j] = 0;
        }
    }
    
    for (auto iter = melt.begin(); iter!=melt.end(); iter++)
        cheese[(*iter).first][(*iter).second] = 0;

    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cheese.assign(n+1, vector<int>(m, 0));

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<m; j++)
            cin >> cheese[i][j];
    }

    int answer = 0;
    while (1)
    {
        if (!Solve())
            break;
        answer ++;
    }

    cout << answer;
    return 0;
}