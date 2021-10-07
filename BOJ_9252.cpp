//21 09 08 > 21 10 07

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1000][1000];
string a;
string b;
string result;

int LCS(int x, int y)
{
    if (x == a.size() || y == b.size())
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (a[x] == b[y])
        return dp[x][y] = 1 + LCS(x+1, y+1);
    
    return dp[x][y] = max(LCS(x+1, y), LCS(x, y+1));
}

void Backtracking(int x, int y)
{
    if (x == a.size() || y == b.size())
        return;

    if (a[x] == b[y])
    {
        result+=a[x];
        Backtracking(x+1, y+1);
        return;
    }
    
    if (dp[x+1][y] > dp[x][y+1])
        Backtracking(x+1, y);
    else
        Backtracking(x, y+1);
}

int main(void)
{
    cin >> a >> b;
    for (auto i=0; i<a.size(); i++)
    {
        for (auto j=0; j<b.size(); j++)
            dp[i][j] = -1;
    }

    cout << LCS(0, 0) << "\n";
    Backtracking(0,0);
    cout << result;

    return 0;
}