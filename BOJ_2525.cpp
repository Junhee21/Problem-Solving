// 22 / 1 / 17

#include <iostream>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    b += c;
    while (b >= 60)
    {
        a += 1;
        b -= 60;
    }
    while (a >= 24)
    {
        a -= 24;
    }

    cout << a << " " << b;
    return 0;
}