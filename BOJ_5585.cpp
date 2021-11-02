// 21/11/02

#include <iostream>
using namespace std;

int how_much(int n)
{
    int coin[6] = {500,100,50,10,5,1};
    int answer = 0;
    int cash = 1000-n;
    for (int i=0; i<6; i++)
    {
        answer += cash/coin[i];
        cash %= coin[i];
    }
    return answer;
}

int main(void)
{
    int n;
    cin >> n;
    cout << how_much(n);
    return 0;
}