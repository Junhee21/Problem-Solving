//21 10 13

#include <iostream>
#include <string>
using namespace std;
const long long r = 31;
const long long M = 1234567891;
long long result = 0;

long long arr[50];

void Fill_arr(string s, int n)
{
    for (int i=0; i<n; i++)
        arr[i] = s[i] - 'a' + 1;
}

void Solve(int n)
{
    long long temp = 1;
    for (int i=0; i<n; i++)
    {
        result += (temp*arr[i])%M;
        temp*=r;
        temp%=M;
    }
    result %= M;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    
    Fill_arr(s, n);
    Solve(n);

    cout << result;
    return 0;
}