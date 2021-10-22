// 21/10/22

#include <iostream>
using namespace std;

int dp[1000+1] = {1,1,};

int DFS(int n)
{
    if (dp[n])
        return dp[n];
    return dp[n] = (DFS(n-1) + 2*DFS(n-2))%10007;
}

int main(void)
{
    int n;
    cin >> n;
    cout << DFS(n);
    return 0;
}