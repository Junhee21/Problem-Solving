// 22 / 1 / 19

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> input;
vector<int> arr;
vector<int> lis;
vector<int> check;

void initArr(void)
{
    lis.push_back(input[0].second);
    arr[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (input[i].second > lis.back())
        {
            arr[i] = lis.size();
            lis.push_back(input[i].second);
        }
        else
        {
            int index = upper_bound(lis.begin(), lis.end(), input[i].second) - lis.begin();
            arr[i] = index;
            lis[index] = input[i].second;
        }
    }
}

void solve(void)
{
    int num = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == num)
        {
            check[i] = true;
            num--;
        }
        if (num == -1)
            break;
    }
    cout << n - lis.size() << "\n";
    for (int i = 0; i < n; i++)
    {
        if (!check[i])
            cout << input[i].first << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    input.assign(n, {0, 0});
    arr.assign(n, 0);
    check.assign(n, false);

    for (int i = 0; i < n; i++)
        cin >> input[i].first >> input[i].second;
    sort(input.begin(), input.end());

    initArr();
    solve();

    return 0;
}