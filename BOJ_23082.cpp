//21 10 03

#include <iostream>
#include <vector>
using namespace std;

vector<int> list_3;

void Trans_3(int num)
{
    int a = num%3;
    int b = num/3;
    if (a == 2)
    {
        list_3.push_back(-1);
        Trans_3(b+1);
        return ;
    }
    if (a == -2)
    {
        list_3.push_back(1);
        Trans_3(b-1);
        return ;        
    }
    list_3.push_back(a);
    if (b != 0)
        Trans_3(b);
}

void Print_trans_3(void)
{
    for(auto iter = list_3.rbegin(); iter!=list_3.rend(); iter++)
    {
        if (*iter == -1)
            cout<<"T";
        else
            cout<<*iter;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin>>num;

    Trans_3(num);
    Print_trans_3();

    return 0;
}