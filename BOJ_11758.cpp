//21 10 09

#include <iostream>
using namespace std;

int ax, ay, bx, by, cx, cy;

int Find_determinant(void)
{
    int vector1_x = ax - bx;
    int vector1_y = ay - by;
    int vector2_x = cx - bx;
    int vector2_y = cy - by;

    return vector1_x*vector2_y - vector1_y*vector2_x;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int d = Find_determinant();

    if (d>0)
        cout<<-1;
    else if (d==0)
        cout<<0;
    else
        cout<<1;

    return 0;
}