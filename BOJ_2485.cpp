// 21 / 12 / 17

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<bool> check;

vector<int> solve(vector<int> a)
{
    sort(a.begin(), a.end());
    int x = a[0];
    vector<int> output = {x};
    for (int i = 1; i < (int)a.size(); i++)
    {
        if (a[i] % x == 0)
            continue;
        output.push_back(a[i] % x);
    }
    return output;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    arr.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> gap;
    for (int i = 0; i < n - 1; i++)
        gap.push_back(arr[i + 1] - arr[i]);

    vector<int> gcd = gap;
    while (gcd.size() > 1)
    {
        gcd = solve(gcd);
    }

    int answer = 0;
    for (int i = 0; i < (int)gap.size(); i++)
        answer += (gap[i] / gcd[0] - 1);

    cout << answer;
    return 0;
}