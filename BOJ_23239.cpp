// 21/10/20

#include <iostream>
using namespace std;

long long w, h, L;

long long Solve(void)
{
    long long answer = 0;

    long long temp = L-1;
    for (long long i=1; i<=L-1; i++)
    {
        while (i*i + temp*temp > L*L)
            temp--;
        answer+=temp;
    }
    answer *= 3;
    answer += (L*2);

    if (L>w)
    {
        answer += (L-w);
        temp = L-w-1;
        long long new_L = L-w;
        for (long long i=1; i<=h; i++)
        {
            if (i==new_L)
                break;
            while (i*i + temp*temp > new_L*new_L)
                temp--;
            answer += temp;
        }
    }
    if (L>h)
    {
        answer += (L-h);
        temp = L-h-1;
        long long new_L = L-h;
        for (long long i=1; i<=w; i++)
        {
            if (i==new_L)
                break;
            while (i*i + temp*temp > new_L*new_L)
                temp--;
            answer += temp;
        }
    }

    if (L > w+h)
    {
        long long rad1 = L-h;
        long long rad2 = L-w;
        for (long long i=1; 1; i++)
        {
            while ((temp*temp + (i+w)*(i+w) > rad1*rad1) && (i*i + (h+temp)*(h+temp) > rad2*rad2))
            {
                temp--;
                if (temp<0)
                    break;
            }
            if (temp <0)
                break;
            answer += temp;
        }
    }

    return answer;
}


int main(void)
{
    cin >> w >> h >> L;
    cout << Solve();
    return 0;
}