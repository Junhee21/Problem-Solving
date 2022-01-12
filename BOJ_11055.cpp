// 22 / 1 / 11

#include <iostream>
#include <vector>
using namespace std;

int n, answer;
vector<int> arr;
vector<int> dp;

int main(void)
{
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] > arr[j]) && (arr[i] + dp[j] > dp[i]))
                dp[i] = arr[i] + dp[j];
        }
        if (dp[i] > answer)
            answer = dp[i];
    }
    cout << answer;
    return 0;
}