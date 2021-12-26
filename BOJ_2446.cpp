// 21 / 12 / 26

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int empty;
        if (i < n)
            empty = i;
        else
            empty = 2 * n - i - 2;
        for (int j = 0; j < empty; j++)
            cout << " ";
        for (int j = 0; j < 2 * n - 1 - 2 * empty; j++)
            cout << "*";
        for (int j = 0; j < empty; j++)
            cout << " ";
        cout << "\n";
    }
    return 0;
}