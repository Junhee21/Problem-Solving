// 21/11/14

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> matrix;
vector<vector<pair<int, int>>> length;
vector<pair<int, int>> locChicken;
vector<pair<int, int>> locHouse;
vector<bool> checkChicken;

int n, m, house, chicken;
int answer = 987654321;

int sumAbsolute(int x, int y)
{
    if (x-y > 0)
        return (x-y);
    else
        return (y-x);
}

void DFS(int level, int node)
{
    if (level==m)
    {
        int nowAnswer=0;
        for (int i=0; i<house; i++)
        {
            for (int j=0; j<chicken; j++)
            {
                if (checkChicken[length[i][j].second])
                {
                    nowAnswer+=length[i][j].first;
                    break;
                }
            }
        }

        if (nowAnswer < answer)
            answer = nowAnswer;
        return;
    }

    for (int i=node+1; i<chicken; i++)
    {
        if (checkChicken[i])
            continue;
        checkChicken[i] = true;
        DFS(level+1, i);
        checkChicken[i] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    matrix.assign(n, vector<int>(n, 0));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
        {
            int x;
            cin >> x;
            if (x==1)
            {
                house++;
                locHouse.push_back({i, j});
            }
            if (x==2)
            {
                chicken++;
                locChicken.push_back({i, j});
            }
            matrix[i][j] = x;
        }
    }

    checkChicken.assign(chicken, false);
    length.assign(house, vector<pair<int, int>>(0, {0,0}));

    for (int i=0; i<house; i++)
    {
        int h_r = locHouse[i].first;
        int h_c = locHouse[i].second;
        for (int j=0; j<chicken; j++)
        {
            int ch_r = locChicken[j].first;
            int ch_c = locChicken[j].second;
            length[i].push_back({sumAbsolute(h_r, ch_r) + sumAbsolute(h_c, ch_c), j});
        }
        sort(length[i].begin(), length[i].end());
    }

    DFS(0, -1);


    cout <<answer;

    return 0;
}