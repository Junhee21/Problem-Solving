// 22 / 1 / 4

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main(void)
{
    long long answer = 0;
    int n;
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int b, c;
    cin >> b >> c;

    for (int i = 0; i < n; i++)
    {
        answer++;
        arr[i] -= b;
        if (arr[i] < 0)
            arr[i] = 0;
        answer += arr[i] / c;
        if (arr[i] % c != 0)
            answer++;
    }
    cout << answer;
    return 0;
}