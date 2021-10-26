// 21/10/26

#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> cartesian(101, vector<bool>(101, false));
vector<pair<int, int>> dxdy = {{1,0},{0,-1},{-1,0},{0,1}};

pair<int, int> Curl_ClockWise(pair<int, int> node)
{
    return make_pair((-1)*node.second, node.first);
}

void Curve_dragon(vector<pair<int, int>>&v, int now, int level)
{
    if (now == level)
        return;

    int axis_x = v.back().first;
    int axis_y = v.back().second;
    for (int i = v.size()-1; i>=0; i--)
    {
        int x = v[i].first-axis_x;
        int y = v[i].second-axis_y;
        pair<int,int>curl_node = Curl_ClockWise({x,y});
        cartesian[(curl_node.first)+axis_x][(curl_node.second)+axis_y] = true;
        v.push_back({(curl_node.first)+axis_x, (curl_node.second)+axis_y});
    }
    Curve_dragon(v, now+1, level);
}

int Output(void)
{
    int answer = 0;
    for (int x=0; x<100; x++)
    {
        for (int y=0; y<100; y++)
        {
            if (cartesian[x][y]&&cartesian[x+1][y]&&cartesian[x][y+1]&&cartesian[x+1][y+1])
                answer++;
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int start_x, start_y, direction, level;
        cin >> start_x >> start_y >> direction >> level;
        pair<int, int> end_point = {start_x+dxdy[direction].first, start_y+dxdy[direction].second};
        cartesian[start_x][start_y] = true;
        cartesian[end_point.first][end_point.second] = true;
        vector<pair<int, int>> Dragon = {{start_x, start_y}, end_point};
        Curve_dragon(Dragon, 0, level);
    }
    cout<<Output();
    return 0;
}