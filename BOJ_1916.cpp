// 21/11/15

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> edge[1001];
vector<int> score(1001, 987654321);
priority_queue<pair<int, int>> pq;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    int start, target;
    cin >> start >> target;

    score[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (node == target)
        {
            cout << cost;
            break;
        }

        for (auto iter = edge[node].begin(); iter != edge[node].end(); iter++)
        {
            if (score[(*iter).first] <= ((*iter).second + cost))
                continue;
            score[(*iter).first] = ((*iter).second + cost);
            pq.push({(-((*iter).second + cost)), (*iter).first});
        }
    }

    return 0;
}