// 21/11/14

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> edge;
vector<int> score;
int n, m, r;

int search(int node)
{
    int nowScore = 0;
    vector<bool> check(n + 1, false);
    priority_queue<pair<int, int>> pq;
    pq.push({0, node});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (cost > m)
            break;
        if (check[nowNode])
            continue;
        check[nowNode] = true;
        nowScore += score[nowNode];
        for (auto iter = edge[nowNode].begin(); iter != edge[nowNode].end(); iter++)
        {
            int newNode = (*iter).first;
            int newCost = (*iter).second + cost;
            pq.push({-newCost, newNode});
        }
    }

    return nowScore;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    score.assign(n + 1, 0);
    edge.assign(n + 1, vector<pair<int, int>>(0, {0, 0}));
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
    {

        int nowScore = search(i);

        if (nowScore > answer)
            answer = nowScore;
    }

    cout << answer;
    return 0;
}