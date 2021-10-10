//21 10 10

#include <iostream>
using namespace std;

int main(void)
{
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int a1, a2, b1, b2;
    if ((x1-x3)*(y2-y3)-(y1-y3)*(x2-x3) > 0)
        a1 = 1;
    else
        a1 = -1;
    if ((x1-x4)*(y2-y4)-(y1-y4)*(x2-x4) > 0)
        a2 = 1;
    else
        a2 = -1;
    if ((x3-x1)*(y4-y1)-(y3-y1)*(x4-x1) > 0)
        b1 = 1;
    else
        b1 = -1;
    if ((x3-x2)*(y4-y2)-(y3-y2)*(x4-x2) > 0)
        b2 = 1;
    else
        b2 = -1;

    if (a1*a2<0 && b1*b2<0)
        cout<<1;
    else
        cout<<0;

    return 0;
}