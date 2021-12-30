// 21 / 12 / 30

#include <iostream>
#include <vector>
using namespace std;

vector<long long> twoSquare(60, 0);

long long howOne(long long n)
{
    if (n <= 0)
        return 0;
    int index = 59;
    while (twoSquare[index] - 1 > n)
        index--;
    long long output = twoSquare[index - 1] * index;
    n -= (twoSquare[index] - 1);
    return output + n + howOne(n - 1);
}

int main(void)
{
    long long a, b;
    cin >> a >> b;

    twoSquare[0] = 1;
    for (int i = 1; i < 60; i++)
        twoSquare[i] = twoSquare[i - 1] * 2;

    cout << howOne(b) - howOne(a-1);
    return 0;
}