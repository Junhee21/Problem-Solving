// 21/10/24

#include <iostream>
#include <iostream>
using namespace std;

int n, m, x, y, answer;
bool dp[80000];

int ABS(int num)
{
    if (num >= 0)
        return num;
    else
        return -num;
}

void Input(void)
{
    cin >> n >> m >> x >> y;
    int temp = max(n, m);
    for (int i=temp*-1; i<=temp; i++)
        dp[40000+i] = false;
}

void Solve(int a, int b, int gap, int num)
{
    if (a > n)
        a = 1;
    if (b > m)
        b = 1;
    if (gap==(x-y))
    {
        answer = (num+(x-a));
        return;
    }
    if (dp[40000+gap])
    {
        answer = -1;
        return;
    }
    dp[40000+gap] = true;
    if ((n-a) > (m-b))
        Solve(a+m-b+1, 1, a+m-b, num+m-b+1);
    else
        Solve(1, b+n+1-a, a-b-n, num+n+1-a);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        Input();
        answer = 0;
        Solve(1, 1, 0, 1);
        cout << answer <<"\n";
    }
    return 0;
}