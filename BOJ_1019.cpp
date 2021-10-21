// 21/10/21

#include <iostream>
using namespace std;

long long arr[10];
long long n;

void Solve(void)
{
    long long chiper = 1;
    long long c= 0;
    while (1)
    {
        if (chiper*10 > n)
            break;
        chiper *= 10;
        c ++;
    }

    bool first_zero_check = true;
    while (c>=0)
    {
        long long num = n/chiper;
        n%=chiper;
        if (num > 0)
        {
            for (int i=0; i<10; i++)
                arr[i] += (num*chiper*c/10);
        }
        for (int i=0; i<num; i++)
            arr[i] += chiper;
        arr[num] += (n+1);

        if (first_zero_check)
        {
            int temp = chiper;
            while (temp)
            {
                arr[0] -= temp;
                temp /= 10;
            }
            first_zero_check = false;
        }

        chiper /= 10;
        c --;
    }
}


int main(void)
{
    cin >> n;

    Solve();

    for (int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    return 0;
}