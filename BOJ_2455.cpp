// 22 / 1 / 4

#include <iostream>
using namespace std;

int main(void)
{
    int num = 0;
    int answer = 0;
    for (int i = 0; i < 4; i++)
    {
        int a, b;
        cin >> a >> b;
        num += (b - a);
        if (num > answer)
            answer = num;
    }
    cout << answer;
    return 0;
}