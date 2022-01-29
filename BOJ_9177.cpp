// 22 / 1 / 29

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<bool>> dp;
string a, b, c;

void search(int x, int y)
{
    if (dp[x][y])
        return;

    dp[x][y] = true;

    if (x + y == (int)c.size())
        return;

    if (x == a.size())
    {
        if (b[y] == c[x + y])
            search(x, y + 1);
        return;
    }
    if (y == b.size())
    {
        if (a[x] == c[x + y])
            search(x + 1, y);
        return;
    }

    if (a[x] == c[x + y])
        search(x + 1, y);
    if (b[y] == c[x + y])
        search(x, y + 1);
}

int main(void)
{
    int tsetCase;
    cin >> tsetCase;
    for (int i = 1; i <= tsetCase; i++)
    {
        cin >> a >> b >> c;
        dp.assign((int)a.size() + 1, vector<bool>((int)b.size() + 1, false));
        search(0, 0);

        cout << "Data set " << i;
        if (dp[(int)a.size()][(int)b.size()])
            cout << ": yes\n";
        else
            cout << ": no\n";
    }
    return 0;
}