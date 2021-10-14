//21 10 14

#include <iostream>
using namespace std;

int n, r, c;
int result = 0;

void Divide(int ra, int rb, int ca, int cb)
{
    if ((rb-ra)==1)
        return;

    int dx = (rb-ra)/2;
    if (r<ra+dx)
    {
        if (c<ca+dx)
            Divide(ra, ra+dx, ca, ca+dx);
        else
        {
            result += dx*dx;
            Divide(ra, ra+dx, ca+dx, cb);
        }
    }
    else
    {
        if (c<ca+dx)
        {
            result += 2*dx*dx;
            Divide(ra+dx, rb, ca, ca+dx);
        }
        else
        {
            result += 3*dx*dx;
            Divide(ra+dx, rb, ca+dx, cb);
        }
    }
}

int main(void)
{
    cin >> n >> r >> c;
    int num = 1;
    for (int i=0; i<n; i++)
        num*=2;
    Divide(0, num, 0, num);
    cout << result;
    return 0;
}