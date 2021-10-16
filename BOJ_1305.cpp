//21 10 16

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
string s;
vector<int> arr;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    arr.assign(n, 0);

    int j=0;
    for (int i=1; i<n; i++)
    {
        while (j>0&&s[i]!=s[j])
            j = arr[j-1];
        if (s[i]==s[j])
            arr[i] = ++j;
    }

    cout << n - arr[n-1];

    return 0;
}