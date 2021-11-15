// 21/11/15

#include <iostream>
using namespace std;

const long long  x = 1000000007;

long long inverseModular (long long num, int quotient)
{
    if (quotient == 1)
        return num;

    long long temp = inverseModular(num, quotient/2);
    long long temp1 = (temp*temp)%x;

    if (quotient %2 == 1)
        return (temp1*num)%x;

    return temp1;
}

int main(void)
{
    long long accum = 0;
    int T;
    cin >> T;
    while (T--)
    {
        long long a, b;
        cin >> a >> b;
        accum += (b*inverseModular(a, x-2));
        accum %= x;
    }

    cout << accum;
    return 0;
}