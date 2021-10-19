// 21/10/19

#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, int>> hanoi;
int dp[25];
int m;

int Hanoi_dp(int level)
{   
    if (level == 0)
        return hanoi[level].second;
    if (dp[level])
        return dp[level];
    return dp[level] = hanoi[level].second+2*Hanoi_dp(level-1);
}

int DFS(int level, int state)
{
    char color = hanoi[level].first;
    int num = hanoi[level].second;

    if (level == 0)
    {
        if (color=='G' || (color=='R'&&state==1) || (color=='B'&&state==0))
            return num;
        if ((color=='R'&&state==0) || (color=='B'&&state==1))
            return 2*num-1;
    }

    if (num==1)
        return Hanoi_dp(level-1)+num+DFS(level-1, 0);

    if (color=='G' || (color=='R'&&state==1) || (color=='B'&&state==0))
        return Hanoi_dp(level-1)+num+DFS(level-1, 0);
    if ((color=='R'&&state==0) || (color=='B'&&state==1))
        return 2*Hanoi_dp(level-1)+2*num+DFS(level-1, 1);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    for (int i=0; i<m; i++)
    {
        char color;
        int num;
        cin >> color >> num;
        hanoi.push_back(make_pair(color, num));
    }

    cout << DFS(m-1, 1);

    return 0;
}