// 21 / 12 / 28

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

        for (int j = 0; j < n - x; j++)
            cout << " ";
        for (int j = 0; j < 2 * x - 1; j++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}