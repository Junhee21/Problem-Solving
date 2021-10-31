// 21/11/01

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> building(1001, 0);
vector<vector<int>> seq(1001, vector<int>(0, 0));
vector<int> dp(1001, 0);
int n, k, target;

void Input(void)
{
    for (int i=1; i<=n; i++)
    {
        cin >> building[i];
        seq[i].clear();
        dp[i] = -1;
    }
}

void Input_seq(void)
{
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        seq[b].push_back(a);
    }
}

int Solve(int num)
{
    if (dp[num]!=-1)
        return dp[num];

    vector<int> arr;
    for (int i=0; i<(int)seq[num].size(); i++)
        arr.push_back(Solve(seq[num][i]));
        
    if (arr.empty())
        return dp[num] = building[num];
    else
        return dp[num] = building[num]+*max_element(arr.begin(), arr.end());
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        Input();
        Input_seq();
        cin >> target;

        cout << Solve(target) <<"\n";
    }
    return 0;
}