// 21/10/29

#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> fish(17, {{0, 0}, 0});
pair<int, int> dir[9] = {
    {0,0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1},
    {1, 0}, {1, 1}, {0, 1}, {-1, 1} };

vector<pair<int, int>>check;
int answer = 0;

int Input(void)
{
    int first_shark = 0;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            int x, y;
            cin >> x >> y;
            fish[x] = {{i, j}, y};
            if (i==0 && j==0)
            {
                fish[x].first.first = -1;
                fish[0].second = y;
                first_shark = x;
            }
        }
    }
    return first_shark;
}

vector<pair<pair<int, int>, int>> Move_fish(vector<pair<pair<int, int>, int>>para)
{
    for (int i=1; i<=16; i++)
    {
        if (para[i].first.first == -1)
            continue;
        int feed_r = para[i].first.first;
        int feed_c = para[i].first.second;
        int feed_dir = para[i].second;
        feed_dir--;

        while (1)
        {
            feed_dir++;
            if (feed_dir == 9)
                feed_dir = 1;
            int new_r = feed_r+dir[feed_dir].first;
            int new_c = feed_c+dir[feed_dir].second;
            if (new_r<0||new_r==4||new_c<0||new_c==4)
                continue;
            if (new_r==para[0].first.first&&new_c==para[0].first.second)
                continue;

            bool c = true;
            for (int j=1; j<=16; j++)
            {
                if (i==j)
                    continue;
                if (para[j].first.first == new_r && para[j].first.second == new_c)
                {
                    pair<int, int> temp = para[i].first;
                    para[i] = para[j];
                    para[i].second = feed_dir;
                    para[j].first = temp;
                    c = false;
                    break;
                }
            }
            if (c)
                para[i] = {{new_r, new_c}, feed_dir};
            break;
        }
    }
    return para;
}

void DFS(int eating, vector<pair<pair<int, int>, int>> para)
{
    int shark_r = para[0].first.first;
    int shark_c = para[0].first.second;
    int shark_dir = para[0].second;

    vector<pair<pair<int, int>, int>>now_fish = Move_fish(para);
    
    for (int i=1; 1; i++)
    {
        int new_r = shark_r+i*dir[shark_dir].first;
        int new_c = shark_c+i*dir[shark_dir].second;
        if (new_r<0||new_r==4||new_c<0||new_c==4)
            break;
        for (int i=1; i<=16; i++)
        {
            if (new_r==now_fish[i].first.first&&new_c==now_fish[i].first.second)
            {
                pair<pair<int, int>, int> temp = now_fish[0];
                now_fish[0] = now_fish[i];
                now_fish[i].first.first = -1;
                DFS(eating+i, now_fish);
                now_fish[i] = now_fish[0];
                now_fish[0] = temp;
                break;
            }
        }
    }
    if (eating > answer)
        answer = eating;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int first_shark = Input();
    DFS(first_shark, fish);
    cout << answer;
    return 0;
}