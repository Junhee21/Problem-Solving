// 21/11/11

#include <iostream>
#include <string>
using namespace std;

int month[11]={31,28,31,30,31,30,31,31,30,31,30};
string day[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void)
{
    int m, d;
    cin >> m >> d;
    int howDady = 0;
    for (int i=0; i<m-1; i++)
        howDady += month[i];

    howDady += (d-1);
    cout << day[howDady%7];

    return 0;
}