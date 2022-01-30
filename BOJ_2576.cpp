// 22 / 1 / 30

#include <iostream>
using namespace std;

int main(void)
{
    int minNum = 100, sum = 0;
    for (int i = 0; i < 7; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
            continue;
        sum += x;
        if (x < minNum)
            minNum = x;
    }
    if (sum == 0)
        cout << -1;
    else
        cout << sum << "\n" << minNum;
    return 0;
}