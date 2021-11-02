// 21/11/02

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<long long> pq;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        long long x;
        cin >> x;
        pq.push(-x);
    }

    long long answer = 0;
    if (n > 1)
    {
        while (1)
        {
            long long x = -pq.top();
            pq.pop();
            long long y = -pq.top();
            pq.pop();
            answer += (x+y);
            if (pq.empty())
                break;
            pq.push(-(x+y));
        }
    }
    cout << answer;
    return 0;
}