// 21/11/06

#include <iostream>
#include <queue>
using namespace std;

long long start, target;

int Solve()
{
    queue<pair<long long, int>> q;
    q.push({start, 1});

    while (!q.empty())
    {
        long long now = q.front().first;
        int step = q.front().second;
        q.pop();
        if (now > target)
            continue;
        if (now == target)
            return step;
        q.push({now*2, step+1});
        q.push({now*10+1, step+1});
    }
    return -1;
}

int main(void)
{
    cin >> start >> target;

    cout << Solve();
    return 0;
}