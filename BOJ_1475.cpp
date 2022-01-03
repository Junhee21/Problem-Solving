// 22 / 1 / 3

#include <iostream>
using namespace std;

int arr[10];

int main(void)
{
    int n;
    cin >> n;
    while (n > 0)
    {
        int x = n % 10;
        if (x == 9)
            arr[6]++;
        else
            arr[x]++;
        n /= 10;
    }
    arr[9] = arr[6] / 2;
    arr[6] -= arr[6] / 2;
    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > answer)
            answer = arr[i];
    }
    cout << answer;
    return 0;
}