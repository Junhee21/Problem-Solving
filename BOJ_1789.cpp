// 21/11/02

#include <iostream>
using namespace std;

int main(void)
{
    long long s;
    cin >> s;

    int answer = 1;
    for (int i=1; 1; i++)
    {
        if (s-i == 0)
            break;
        if (s-i <= i)
            continue;
        s-=i;
        answer ++;
    }
    cout << answer;
    return 0;
}