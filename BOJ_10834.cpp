// 22 / 2 / 8

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    long long dir = 0, rpm = 1;
    while (n--)
    {
        long long rev_i, rev_i_1, dir_i;
        cin >> rev_i >> rev_i_1 >> dir_i;
        if (dir_i == 1)
        {
            dir = 1 - dir;
        }
        rpm *= rev_i_1;
        rpm /= rev_i;
    }
    cout << dir << " " << rpm;
    return 0;
}