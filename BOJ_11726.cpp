// 21/10/22

#include <iostream>
using namespace std;

int dp[1000+1] = {1,1,};

int DFS(int node)
{
    if (dp[node])
        return dp[node];
    return dp[node] = (DFS(node-1)+DFS(node-2))%10007;
}

int main(void)
{
    int n;
    cin >> n;
    cout << DFS(n);

    return 0;
}