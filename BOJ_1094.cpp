// 22 / 1 / 11

#include <iostream>
using namespace std;

int main(void)
{
    int x = 0, minStick = 64, now = 0, answer = 1;
    cin >> x;

    while (true)
    {
        if (minStick + now == x)
            break;
        minStick /= 2;
        if (now + minStick < x)
        {
            now += minStick;
            answer++;
        }
    }
    cout << answer;
    return 0;
}