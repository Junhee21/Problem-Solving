// 22 / 1 / 24

#include <iostream>
using namespace std;

int main(void)
{
    int x = 0, answer = 0;
    cin >> x;
    for (int i = 0; i < 5; i++)
    {
        int y;
        cin >> y;
        if (x == y)
            answer++;
    }
    cout << answer;
    return 0;
}