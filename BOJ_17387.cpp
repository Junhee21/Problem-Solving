//21 10 11

#include <iostream>
using namespace std;

int ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy)
{
    long long ccw1 = (bx-ax)*(cy-ay) - (by-ay)*(cx-ax);

    if (ccw1 >0)
        return 1;
    else if (ccw1 <0)
        return -1;
    else
        return 0;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax>> ay>> bx>> by>> cx>> cy>> dx>> dy;

    int p1 = ccw(ax, ay, bx, by, cx, cy);
    int p2 = ccw(ax, ay, bx, by, dx, dy);
    int q1 = ccw(cx, cy, dx, dy, ax, ay);
    int q2 = ccw(cx, cy, dx, dy, bx, by);
    

    if ((p1*p2==0)&&(q1*q2==0))
    {
        if (ax==bx)
        {
            if (((cy-ay)*(cy-by)<=0)||((dy-ay)*(dy-by)<=0)||((ay-cy)*(ay-dy)<=0)||((by-cy)*(by-dy)<=0))
                cout<<1;
            else
                cout<<0;
        }
        else
        {
            if (((cx-ax)*(cx-bx)<=0)||((dx-ax)*(dx-bx)<=0)||((ax-cx)*(ax-dx)<=0)||((bx-cx)*(bx-dx)<=0))
                cout<<1;
            else
                cout<<0;
        }
    }
    else if ((p1*p2 <= 0)&&(q1*q2<=0))
        cout << 1;
    else
        cout << 0;

    return 0; 
}