// 21/10/22

#include <iostream>
using namespace std;

pair<int ,int> dp[1000][1000];
int arr[1000];
int n;

void Input(void)
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
        for (int j=0; j<n; j++)
            dp[i][j] = {-1, -1};
    }
}

pair<int, int> MW(int first, int last);
pair<int, int> GW(int first, int last);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        Input();
        cout << GW(0, n-1).first <<"\n";
    }
    return 0;
}

pair<int, int> GW(int first, int last)
{
    if (first == last)
        return {arr[first], 0};
    if (dp[first][last].first != -1)
        return dp[first][last];

    pair<int, int> temp1 = MW(first+1, last);
    temp1.first += arr[first];
    pair<int, int> temp2 = MW(first, last-1);
    temp2.first += arr[last];

    if (temp1.first > temp2.first)
        return dp[first][last] = temp1;
    else
        return dp[first][last] = temp2;
}

pair<int, int> MW(int first, int last)
{
    if (first == last)
        return {0, arr[first]};

    if (dp[first][last].second != -1)
        return dp[first][last];

    pair<int, int> temp1 = GW(first+1, last);
    temp1.second += arr[first];
    pair<int, int> temp2 = GW(first, last-1);
    temp2.second += arr[last];    

    if (temp1.second > temp2.second)
        return dp[first][last] = temp1;
    else
        return dp[first][last] = temp2;
}