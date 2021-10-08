//21 10 08

#include <iostream>
#include <algorithm>
using namespace std;
const int divided = 1000000003;

int n, k;
long long dp[1001][1001];

long long Combination(int a, int b)
{
    if (dp[a][b])
        return dp[a][b];
    if (dp[a][a-b])
    {
        dp[a][b] = dp[a][a-b];
        return dp[a][b];
    }
    if (a==b || b==0)
    {
        dp[a][b] = 1;
        return 1;
    }
    if (b==1)
    {
        dp[a][b] = a;
        return a;
    }

    return dp[a][b] = (Combination(a-1, b-1)+Combination(a-1, b))%divided;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if (k*2 > n)
        cout<<0;
    else
    {
        if (k==1)
            cout<<n;
        else
        {
            long long a = Combination(n-k, k);
            long long b = Combination(n-k-1, k-1);
            cout <<(a+b)%divided;
        }
    }

    return 0;
}