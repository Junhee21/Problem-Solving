// 21 / 12 / 16

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i=0; i<t; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int beforeNum = 1001;
    for (int i=0; i<t; i++)
    {
        if (arr[i] == beforeNum)
            continue;
        cout << arr[i] << " ";
        beforeNum = arr[i];
    }

    return 0;
}