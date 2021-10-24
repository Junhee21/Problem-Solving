// 21/10/24

#include <iostream>
#include <string>
using namespace std;

int n, m;
bool check[101][101];
int dp[101][101][100];

void Plus_long(int now_n, int now_m, int first_n, int first_m, int second_n, int second_m)
{
    for (int i=99; i>0; i--)
    {
        dp[now_n][now_m][i] += (dp[first_n][first_m][i] + dp[second_n][second_m][i]);
        if (dp[now_n][now_m][i] > 9)
        {
            dp[now_n][now_m][i] %= 10;
            dp[now_n][now_m][i-1] ++;
        }
    }
}

void Combination(int n, int m)
{
    if (check[n][m])
        return;
    if (n==m || m==0)
    {
        check[n][m] = true;
        dp[n][m][99] = 1;
        return;
    }
    Combination(n-1, m);
    Combination(n-1, m-1);
    Plus_long(n, m, n-1, m, n-1, m-1);
    check[n][m] = true;
}

void Output(void)
{
    bool start_point = false;
    for (int i=0; i<100; i++)
    {
        if (dp[n][m][i] != 0)
            start_point = true;
        if (start_point)
            cout << dp[n][m][i];
    }
}

int main(void)
{
    cin >> n >> m;
    Combination(n, m);
    Output();
    return 0;
}