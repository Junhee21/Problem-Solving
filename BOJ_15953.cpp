//21 09 22
#include <iostream>
#include <vector>
using namespace std;

vector<int> kakao_1 = {500,300,300,200,200,200,50,50,50,50};
vector<int> kakao_2;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<5; i++)
        kakao_1.push_back(30);
    for (int i=0; i<6; i++)
        kakao_1.push_back(10);

    int num = 1, money = 512;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<num; j++)
            kakao_2.push_back(money);
        money /= 2;
        num *= 2;
    }
    
    int test_num;
    cin>>test_num;

    while(test_num--)
    {
        int a, b;
        cin>>a>>b;

        int total_money = 0;
        if (a && a<=21)
            total_money += kakao_1[a-1];
        if (b && b<=31)
            total_money += kakao_2[b-1];

        cout<<total_money*10000<<"\n";
    }

    return 0;
}