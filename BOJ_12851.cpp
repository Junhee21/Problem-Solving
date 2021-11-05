// 21//11/05

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int subin, sister;
vector<pair<int,int>> arr(100000+1, {-1,0});
queue<int> q;

void Solve(void)
{
    arr[subin] = {0,1};
    q.push(subin);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (now == sister)
            break;

        if (now > 0)
        {
            if (arr[now-1].first == arr[now].first+1)
                arr[now-1].second += arr[now].second;

            if (arr[now-1].first == -1)
            {
                arr[now-1].first = arr[now].first+1;
                arr[now-1].second = arr[now].second;
                q.push(now-1);
            }
        }
        if (now < 100000)
        {
            if (arr[now+1].first == arr[now].first+1)
                arr[now+1].second += arr[now].second;

            if (arr[now+1].first == -1)
            {
                arr[now+1].first = arr[now].first+1;
                arr[now+1].second = arr[now].second;
                q.push(now+1);
            }
        }
        if (now*2 <= 100000)
        {
            if (arr[now*2].first == arr[now].first+1)
                arr[now*2].second += arr[now].second;

            if (arr[now*2].first == -1)
            {
                arr[now*2].first = arr[now].first+1;
                arr[now*2].second = arr[now].second;
                q.push(now*2);
            }
        }
    }

    cout <<  arr[sister].first << "\n" << arr[sister].second;
}

int main(void)
{
    cin >> subin >> sister;
    Solve();

    return 0;
}