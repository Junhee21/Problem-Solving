//21 10 08

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int n;
int color[1000][3];
int dp[1000][3];

int cost(int node, int c, int first_color)
{
    if (dp[node][c])
        return dp[node][c];

    if (node==n-1)
    {
        if (c==first_color)
            return INF;
        else
            return color[node][c];
    }

    dp[node][c] = color[node][c];
    
    vector<int> temp;
    for (int i=0; i<3; i++)
    {
        if (i==c)
            continue;
        temp.push_back(cost(node+1, i, first_color));
    }

    return dp[node][c] += *min_element(temp.begin(), temp.end());
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<3; j++)
            cin>>color[i][j];
    }

    vector<int> result;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<3; k++)
                dp[j][k] = 0;
        }
        result.push_back(cost(0,i,i));
    }

    cout<<*min_element(result.begin(), result.end());
    return 0;
}