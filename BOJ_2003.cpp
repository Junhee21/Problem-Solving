// 22 / 1 / 21

#include <iostream>
#include <vector>
using namespace std;

int n, m, answer;
vector<int> arr;

int main(void)
{
    cin >> n >> m;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int le = 0, ri = 0, num = arr[0];
    while (true)
    {
        if (num < m)
        {
            num += arr[++ri];
            if (ri == n)
                break;
        }
        else
        {
            if (num == m)
                answer++;
            num -= arr[le++];
            if (le == n)
                break;
            if (le > ri)
                num += arr[++ri];
        }
    }
    cout << answer;
    return 0;
}