//21 09 05

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> dp;
vector<int> course;

void Fill_dp(int start, int finish){
    dp[start] = 0;
    queue<int>qu;
    qu.push(start);
    while(!qu.empty()){
        int node = qu.front();
        int time = dp[node];
        qu.pop();

        if (node==finish)   break;

        if ((node>0)&&(dp[node-1] > time + 1)){
            dp[node-1] = time + 1;
            qu.push(node-1);
        }
        if ((node<100000)&&(dp[node+1] > time + 1)){
            dp[node+1] = time + 1;
            qu.push(node+1);
        }
        if ((node*2<=100000)&&(dp[node*2] > time + 1)){
            dp[node*2] = time + 1;
            qu.push(node*2);
        }
    }
}

void solve(int subin, int sister){
    course.push_back(sister);
    if(subin!=sister){
        if((sister>0)&&(dp[sister-1] == dp[sister] -1))
            solve(subin, sister-1);
        else if((sister<100000)&&(dp[sister+1] == dp[sister] -1))
            solve(subin, sister+1);
        else
            solve(subin, sister/2);
    }
}

int main(void){
    int n, k; cin>>n>>k;
    dp.assign(100001, INF);

    Fill_dp(n, k);
    solve(n, k);
    cout<<dp[k]<<"\n";
    for(int i=course.size()-1; i>=0; i--)
        cout<<course[i]<<" ";
    return 0;
}