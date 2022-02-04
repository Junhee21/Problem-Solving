// 22 / 2 / 4

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n, k;

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int maxSum = -987654321, nowSum = 0, num = 0, le = 0;
    for (int i = 0; i < n; i++)
    {
        nowSum += arr[i];
        if (num < k)
        {
            num++;
        }
        if (num == k)
        {
            maxSum = nowSum > maxSum ? nowSum : maxSum;
            nowSum -= arr[le++];
        }
    }
    cout << maxSum;
    return 0;
}