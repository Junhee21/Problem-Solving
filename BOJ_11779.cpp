//21 09 06

#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<int>tracking;
vector<pair<int, int>>bus[1001];
vector<pair<int, int>>destination;
int n, m, a, b, c, start, finish;

void solve(void){
    destination.assign(1001, {INF, 0});
    destination[start].first = 0;

    priority_queue<pair<int, int>>pq;
    pq.push({0, start});

    while (!pq.empty()){
        int start_node = pq.top().second;
        int start_length = -pq.top().first;
        pq.pop();

        if (start_length>destination[start_node].first)
            continue;

        for (int i=0; i<bus[start_node].size(); i++){
            int end_node = bus[start_node][i].first;
            int end_length = bus[start_node][i].second + start_length;
            if (end_length < destination[end_node].first){
                destination[end_node].first = end_length;
                destination[end_node].second = start_node;
                pq.push({-end_length, end_node});
            }
        }
    }
}

void back_tracking(int x){
    tracking.push_back(x);
    if (x!=start){
        back_tracking(destination[x].second);
    }
}

void answer(void){
    printf("%d\n%d\n", destination[finish].first, tracking.size());
    for (int i=tracking.size()-1; i>=0; i--)
        printf("%d ", tracking[i]);
}

int main(void){
    scanf("%d %d", &n, &m);
    while (m--){
        scanf("%d %d %d", &a, &b, &c);
        bus[a].push_back({b, c});
    }
    scanf("%d %d", &start, &finish);

    solve();
    back_tracking(finish);
    answer();

    return 0;
}