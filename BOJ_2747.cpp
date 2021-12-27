// 21 / 12 / 27

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    int a1 = 0, a2 = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = a2;
        a2 += a1;
        a1 = temp;
    }
    return a2;
}

int main(void)
{
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}