// 21/11/11

#include <iostream>
using namespace std;

int n;

int dp[15];
pair<int, int> pay[15];

int DFS(int day)
{
    if (day == n)
        return 0;

    if (dp[day])
        return dp[day];

    int Counsel = 0, nonCounsel = 0;

    if (pay[day].first+day <= n)
        Counsel = pay[day].second + DFS(day+pay[day].first);
        
    nonCounsel = DFS(day + 1);

    if (Counsel > nonCounsel)
        return dp[day] = Counsel;
    else
        return dp[day] = nonCounsel;
}

int main(void)
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> pay[i].first >> pay[i].second;
    }

    cout << DFS(0);
    return 0;
}