// 22 / 1 / 23

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int k, n;
vector<int> arr;

bool compare(string x, string y)
{
    string x_y = x + y;
    string y_x = y + x;
    for (int i = 0; i < (int)x_y.size(); i++)
    {
        if (x_y[i] > y_x[i])
            return true;
        else if (x_y[i] < y_x[i])
            return false;
    }
    return false;
}

void sortCustom(void)
{
    for (int i = 0; i<n-1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            int x = arr[j];
            int y = arr[j - 1];
            if (compare(to_string(x), to_string(y)))
            {
                int temp = x;
                arr[j] = y;
                arr[j - 1] = temp;
            }
        }
    }
}

int main(void)
{
    cin >> k >> n;
    arr.assign(k, 0);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    int x = arr.back();

    for (int i = 0; i < n - k; i++)
        arr.push_back(x);

    sortCustom();

    for (int i = 0; i < n; i++)
        cout << arr[i];
    return 0;
}