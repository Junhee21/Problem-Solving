//21 10 18

#include <iostream>
#include <string>
using namespace std;

string s[10] = 
{
"black",
"brown",
"red",
"orange",
"yellow",
"green",
"blue",
"violet",
"grey",
"white"
};

long long arr[10];

int main(void)
{
    string a[3];
    cin >> a[0]>> a[1]>> a[2];

    arr[0] = 1;
    for (int i=1; i<10; i++)
        arr[i] = arr[i-1]*10;

    long long x=0;
    for (long long i=0; i<10; i++)
    {
        if (a[0] == s[i])
            x+=i;
    }
    x*=10;
    for (int i=0; i<10; i++)
    {
        if (a[1] == s[i])
            x+=i;
    }
    for (int i=0; i<10; i++)
    {
        if (a[2] == s[i])
            x*=arr[i];
    }

    cout << x;

    return 0;
}