// 21 / 12 / 28

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = 0; j < 2 * n - 1 - 2 * i; j++)
            cout << "*";
        cout << "\n";
    }
    return 0;
}