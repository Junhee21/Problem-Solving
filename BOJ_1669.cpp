// 22  / 1 / 10

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n;

int main(void)
{
    cin >> n;
    arr.assign(n + 1, 987654321);
    arr[0] = 0;
    for (int i = 1; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j++)
        {
            if (arr[j] > arr[j - i * i] + 1)
                arr[j] = (arr[j - i * i] + 1);
        }
    }
    cout << arr[n];
    return 0;
}