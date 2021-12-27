// 21 / 12 / 27

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i < 2 * n; i++)
    {
        int x;
        if (i <= n)
            x = i;
        else
            x = 2 * n - i;
        for (int j = 0; j < x; j++)
            cout << "*";
        for (int j = 0; j < 2 * n - 2 * x; j++)
            cout << " ";
        for (int j = 0; j < x; j++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}