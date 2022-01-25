// 22 / 1 / 25

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> arr;
vector<bool> check;

void input(void)
{
    cin >> n >> m;
    arr.assign(m, {0, 0});
    check.assign(n + 1, false);
    for (int i = 0; i < m; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
}

int solve(void)
{
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        int a = arr[i].second, b = arr[i].first;
        for (int j = a; j <= b; j++)
        {
            if (!check[j])
            {
                check[j] = true;
                answer++;
                break;
            }
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        input();
        cout << solve() << "\n";
    }
    return 0;
}