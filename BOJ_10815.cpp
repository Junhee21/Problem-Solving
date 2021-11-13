// 21/11/13

#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (s.count(x))
            cout << 1;
        else
            cout << 0;
        cout << " ";
    }
    return 0;
}