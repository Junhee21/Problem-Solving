//21 10 12

#include <iostream>
#include <string>
using namespace std;

bool Solve(string num)
{
    int i=0;
    int j=num.size()-1;
    while (1)
    {
        if (i>=j)
            return true;
        if (num[i]!=num[j])
            return false;
        i++;
        j--;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string num;
        cin>>num;
        if (num[0]==48 && num.size()==1)
            break;
        if (Solve(num))
            cout<<"yes"<<"\n";
        else
            cout<<"no"<<"\n";
    }
    return 0;
}