//21 10 12

#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while (n--)
    {
        string order;
        cin >> order;
        if (order == "push")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (order == "pop")
        {
            if (!q.empty())
            {
                cout<<q.front()<<"\n";
                q.pop();
            }
            else
                cout<<-1<<"\n";
        }
        else if (order == "size")
            cout<<q.size()<<"\n";
        else if (order == "empty")
        {
            if (q.empty())
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }
        else if (order == "front")
        {
            if (!q.empty())
                cout << q.front()<<"\n";
            else
                cout<<-1<<"\n";
        }
        else
        {
            if (!q.empty())
                cout << q.back()<<"\n";
            else
                cout<<-1<<"\n";
        }
    }

    return 0;
}