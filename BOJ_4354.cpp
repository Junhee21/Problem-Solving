//21 10 16

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int arr[1000000+5];
string s;

void KMP(void)
{
    int n = (int)s.size();
    for (int i=0; i<n; i++)
        arr[i] =0;

    int j=0;
    for(int i=1;i<n;i++)
    {
        while (j>0&&s[i]!=s[j])
            j=arr[j-1];
        if(s[i]==s[j])
            arr[i]=++j;
    }

    int divided=n-arr[n-1];
    if(n%divided!=0)
        cout<<1<<"\n";
    else
        cout<<n/divided<<"\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string end_check =".";
    while (1)
    {
        cin >> s;
        if (s==end_check)
            break;
        KMP();
    }

    return 0;
}