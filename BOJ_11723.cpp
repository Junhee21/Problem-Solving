//21 09 29
#include <iostream>
#include <string>
using namespace std;

int s = 0;

void do_order(string order)
{
    if (order == "add")
    {
        int x;
        cin >> x;
        s |= (1<<x);
    }
    else if (order == "remove")
    {
        int x;
        cin >> x;
        s &= (~(1<<x));
    }
    else if (order == "check")
    {
        int x;
        cin >> x;
        if (s&(1<<x))
            cout<<"1\n";
        else
            cout<<"0\n";
    }
    else if (order == "toggle")
    {
        int x;
        cin>> x;
        if (s&(1<<x))
            s &= (~(1<<x));
        else
            s |= (1<<x);
    }
    else if (order == "all")
        s = (1<<21)-1;
    else
        s = 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin>>m;

    while (m--)
    {
        string order;
        cin>>order;
        do_order(order);
    }

    return 0;
}