//21 10 04

#include <iostream>
#include <vector>
using namespace std;

int dp[12];

int Solve(int num)
{
    if (dp[num])
        return dp[num];
    
    int x = 0;
    x += Solve(num-1);
    if (num>=2)
        x+= Solve(num-2);
    if (num>=3)
        x+= Solve(num-3);
    dp[num] = x;
    return dp[num];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    cin>>test_case;

    dp[0] = 1;
    while (test_case--)
    {
        int n;
        cin>>n;
        cout<<Solve(n)<<"\n";
    }

    return 0;
}