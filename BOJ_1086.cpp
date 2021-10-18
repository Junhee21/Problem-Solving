//21 10 10

#include <iostream>
#include <string>
using namespace std;

int n, k;
int Remainder[51];
long long a, b;
long long dp[(1<<15)][100];
string arr[15];

int Find_remainder(string num)
{
    int x=0;
    for (auto i = num.begin(); i!=num.end(); i++)
    {
        x *= 10;
        x += (*i)-'0';
        x %= k;
    }
    return x;
}

void Solve(void)
{
    dp[0][0] = 1;
    for (int i=0; i<(1<<n); i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i&(1<<j))
                continue;
            int temp = i|(1<<j);
            int chiper = (int)arr[j].size();
            int R = Find_remainder(arr[j]);
            for (int m=0; m<k; m++)
            {
                int new_num = (Remainder[chiper]*m+R)%k;
                dp[temp][new_num] += dp[i][m];
            }
        }
    }
}

void Find_answer(void)
{
    b=1;
    for (int i=1; i<=n; i++)
        b *= (long long)i;
    a=dp[(1<<n)-1][0];
}

long long GCD(void)
{
    long long Min = a;
    long long Max = b;
    while (1)
    {
        if (Max%Min == 0)
            break;
        long long temp;
        temp = Max%Min;
        Max = Min;
        Min = temp;
    }
    return Min;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cin >> k;
    
    Remainder[0] = 1%k;
    for (int i=1; i<=50; i++)
        Remainder[i] = (Remainder[i-1]*10)%k;

    Solve();
    Find_answer();

    if (a==b)
        cout<<1<<"/"<<1;
    else if (a==0)
        cout<<0<<"/"<<1;
    else
    {
        long long gcd = GCD();
        cout<<a/gcd<<"/"<<b/gcd;
    }
    return 0;
}