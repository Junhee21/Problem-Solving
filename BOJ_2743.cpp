// 22 / 1 / 4

#include <iostream>
using namespace std;

int main(void)
{
    char arr[101];
    cin >> arr;
    int i = 0;
    while (arr[i])
        i++;
    cout << i;
    return 0;
}