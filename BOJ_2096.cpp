// 21/11/10

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
bool check = false;
vector<pair<int, int>> dp;

vector<pair<int, int>> DFS(vector<pair<int, int>>dp)
{
    vector<pair<int, int>> output(3, make_pair(0, 0));

    vector<int> arr(3, 0);
    for (int i=0; i<3; i++)
        cin >> arr[i];
    
    if (!check)
    {
        check = true;
        for (int i=0; i<3; i++)
            output[i].first = output[i].second = arr[i];
        return output;
    }

    for (int i=0; i<3; i++)
    {
        priority_queue<int> max_num;
        priority_queue<int> min_num;
        for (int j=0; j<3; j++)
        {
            if ((i==0&&j==2)||(i==2&&j==0))
                continue;
            max_num.push(dp[j].first);
            min_num.push(-dp[j].second);
        }
        output[i].first = (max_num.top()+arr[i]);
        output[i].second = (-min_num.top()+arr[i]);
    }
    return output;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp.assign(3, {0,0});

    for (int i=0; i<n; i++)
        dp = DFS(dp);

    priority_queue<int> max_num;
    priority_queue<int> min_num;        

    for (int i=0; i<3; i++)
    {
        max_num.push(dp[i].first);
        min_num.push(-dp[i].second);
    }

    cout << max_num.top() <<" "<< -min_num.top();

    return 0;
}