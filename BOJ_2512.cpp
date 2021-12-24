// 21 / 12 / 24

#include <iostream>
#include <vector>
using namespace std;

int n, budget;
vector<int> arr;

bool canPay(int price)
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > price)
            x += price;
        else
            x += arr[i];
    }
    if (x <= budget)
        return true;
    else
        return false;
}

int main(void)
{
    cin >> n;
    arr.assign(n + 1, 0);
    int maxBud = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] > maxBud)
            maxBud = arr[i];
    }
    cin >> budget;

    if (sum <= budget)
        cout << maxBud;
    else
    {
        int low = 0;
        int high = maxBud;

        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            if (canPay(mid))
                low = mid;
            else
                high = mid;
        }
        cout << low;
    }

    return 0;
}