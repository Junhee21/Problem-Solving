// 21/10/25

#include <iostream>
using namespace std;

long long minnum, maxnum;
bool check[1000000+1];
bool prime[1000000+1000];

void Solve(void)
{
    for (long long i=2; 1; i++)
    {
        if (i*i > maxnum)
            break;
        if (prime[i])
            continue;
        for (long long j=i; j<=1001000; j+=i)
            prime[j] = true;
        long long temp = minnum/(i*i);
        for (long long j=temp*(i*i); j<=maxnum; j+=(i*i))
        {
            if (j<minnum)
                continue;
            check[j-minnum] = true;
        }
    }
}

int main(void)
{
    cin >> minnum >> maxnum;
    Solve();
    int answer = 0;
    for (long long i=0; i<=(maxnum-minnum); i++)
    {
        if (!check[i])
            answer ++;
    }
    cout << answer;
    return 0;
}