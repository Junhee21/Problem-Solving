// 21 / 12 / 27

#include <iostream>
using namespace std;

int main(void)
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        char arr[4];
        cin >> arr;
        cout << arr[0] - '0' + arr[2] - '0' << "\n";
    }
    return 0;
}