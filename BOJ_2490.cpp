// 22 / 1 / 3

#include <iostream>
using namespace std;

int main(void)
{
    char arr[5] = {'D', 'C', 'B', 'A', 'E'};
    for (int i = 0; i < 3; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << arr[a + b + c + d] << "\n";
    }
    return 0;
}