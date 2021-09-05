// 21 09 01 > 21 09 02 > 21 09 04
// 다익스트라 알고리즘 사용

#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int t, n, m, k, a, b, c, d;
int dp[101][10001];

int main(void){
    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &n, &m, &k);
        
        vector<pair<int, pair<int, int>>> line[n+1];
        while (k--){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            line[a].push_back(make_pair(b, make_pair(c,d)));
        }

        for (int i=1; i<=n; i++){
            for (int j=0; j<=m; j++)
                dp[i][j] = INF;
        }

        dp[1][0] = 0;
        priority_queue<pair<int, pair<int, int>>>pq;
        pq.push({0,{0,1}});

        while (!pq.empty()){
            int start_time = -pq.top().first;
            int start_cost = pq.top().second.first;
            int start_node = pq.top().second.second;
            pq.pop();

            if (dp[start_node][start_cost] < start_time)    continue;
            for (int i=0; i<line[start_node].size(); i++){
                int next_time = start_time + line[start_node][i].second.second;
                int next_cost = start_cost + line[start_node][i].second.first;
                int next_node = line[start_node][i].first;

                if (next_cost > m)  continue;
                if (dp[next_node][next_cost] > next_time){
                    for (int j=next_cost; j<=m; j++){
                        if (dp[next_node][j] > next_time)
                            dp[next_node][j] = next_time;
                    }
                    pq.push({-next_time, {next_cost, next_node}});
                }
            }
        }
        int min=INF;
        for(int i=0; i<=m; i++){
            if (dp[n][i] < min)
                min = dp[n][i];
        }

        if (min==INF)   printf("Poor KCM\n");
        else    printf("%d\n", min);
    }
    return 0;
}