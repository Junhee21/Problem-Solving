// 22 / 2 / 5

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int m;
    cin >> m;
    while (m--)
    {
        int gender, bulb;
        cin >> gender >> bulb;
        if (gender == 1)
        {
            for (int i = bulb; i <= n; i += bulb)
                arr[i] = 1 - arr[i];
        }
        else
        {
            for (int j = 0; (bulb + j <= n) && (bulb - j >= 1); j++)
            {
                if (arr[bulb + j] != arr[bulb - j])
                    break;
                arr[bulb + j] = 1 - arr[bulb + j];
                if (j == 0)
                    continue;
                arr[bulb - j] = 1 - arr[bulb - j];
            }
        }
    }

    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
        k++;
        if (k == 20)
        {
            cout << "\n";
            k = 0;
        }
    }
    return 0;
}