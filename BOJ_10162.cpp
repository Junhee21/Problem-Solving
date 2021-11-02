// 21/11/02

#include <iostream>
using namespace std;

void microwave(int t)
{
    int button[3] = {300, 60, 10};
    int answer[3];
    for (int i=0; i<3; i++)
    {
        answer[i] = t/button[i];
        t %= button[i];
    }
    if (t==0)
        cout << answer[0] <<" "<< answer[1] <<" "<< answer[2];

    else
        cout << -1;
    return;
}

int main(void)
{
    int t;
    cin >> t;
    microwave(t);
    return 0;
}