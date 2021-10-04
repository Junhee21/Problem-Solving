//21 10 03

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<pair<int, int>, int>> pq;
int finish_time = 0;

void what_process(int n, int i, int k, int t)
{
    if (pq.empty())
    {
        finish_time = i;
        pq.push({{k-i, -t}, -n});
    }
    else if (i<=finish_time)
        pq.push({{k-i, -t}, -n});
    else
    {
        while(!pq.empty())
        {
            cout<<-pq.top().second<<" ";
            finish_time += (-pq.top().first.second);
            pq.pop();
            if (i<=finish_time)
            {
                pq.push({{k-i, -t}, -n});
                break;
            }
        }
    }
}

void empty_pq()
{
    while (!pq.empty())
    {
        cout<<-pq.top().second<<" ";
        pq.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin>>num;

    for (int i=1; i<=num; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        what_process(i, a, b, c);
    }
    empty_pq();

    return 0;
}