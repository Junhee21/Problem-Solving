// 22 / 1 / 1

#include <iostream>
using namespace std;

int arr[4][3];

int main(void)
{
    cin >> arr[0][0] >> arr[0][1] >> arr[0][2];

    arr[1][0] = 15;
    arr[1][1] = 28;
    arr[1][2] = 19;
    int n = 15 * 28 * 19;
    for (int i = 0; i < 3; i++)
    {
        arr[2][i] = n / arr[1][i];
        while ((arr[2][i] * arr[3][i]) % arr[1][i] != 1)
            arr[3][i]++;
    }

    int answer = 0;
    for (int i = 0; i < 3; i++)
        answer += (arr[0][i] * arr[2][i] * arr[3][i]);

    if (answer % n == 0)
        cout << 7980;
    else
        cout << answer % n;
    return 0;
}