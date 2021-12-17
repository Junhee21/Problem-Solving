// 21 / 12 / 17

#include <iostream>
using namespace std;

long long fibonacci(int n)
{
    long long x1 = 0;
    long long x2 = 1;
    for (int i=1; i<n; i++)
    {
        long long temp = x2;
        x2 += x1;
        x1 = temp;
    }
    return x2;
}

int main(void)
{
    int n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}