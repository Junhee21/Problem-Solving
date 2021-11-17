// 21/11/17

#include <iostream>
using namespace std;

int main(void)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        if (x > 40)
            sum += x;
        else
            sum += 40;
    }
    cout << sum / 5;
    return 0;
}
