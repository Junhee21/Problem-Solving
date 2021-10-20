// 21/10/20

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int matrix[20][20];
int n, shark_r, shark_c;
int r_dx[4] = {1, 0 , -1, 0};
int c_dx[4] = {0 , -1, 0, 1};

void Find_feed(priority_queue<pair<int, pair<int, int>>>&list_feed,
                vector<vector<int>>&cost, int r, int c, int t, int shark_size)
{
    cost[r][c] = t;
    if (matrix[r][c] < shark_size && matrix[r][c])
        list_feed.push({-t, {-r, -c}});

    for (int i=0; i<4; i++)
    {
        int n_r = r + r_dx[i];
        int n_c = c + c_dx[i];
        if (n_r>=0 && n_r<n && n_c>=0 && n_c<n && matrix[n_r][n_c]<=shark_size && cost[n_r][n_c]>t+1)
            Find_feed(list_feed, cost, n_r, n_c, t+1, shark_size);
    }
}

int How_eat(int shark_size, int state)
{
    matrix[shark_r][shark_c] = 0;
    priority_queue<pair<int, pair<int, int>>> list_feed;
    vector<vector<int>> cost;
    for (int i=0; i<n; i++)
    {
        vector<int>temp;
        for (int j=0; j<n; j++)
            temp.push_back(987654321);
        cost.push_back(temp);
    }

    Find_feed(list_feed, cost, shark_r, shark_c, 0, shark_size);
    if (list_feed.empty())
        return 0;
    shark_r = -list_feed.top().second.first;
    shark_c = -list_feed.top().second.second;
    int now_time = -list_feed.top().first;
    int new_shark_size = shark_size;
    int new_state = state+1;
    if (new_state == new_shark_size && new_shark_size <7)
    {
        new_shark_size ++;
        new_state = 0;
    }
    return now_time + How_eat(new_shark_size, new_state);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 9)
            {
                shark_r = i;
                shark_c = j;
            }
        }
    }

    cout << How_eat(2, 0);
    return 0;
}