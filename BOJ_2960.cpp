// 22 / 1 / 28

#include <iostream>
#include <vector>
using namespace std;

vector<bool> check;
int n, k;

int main(void)
{
    cin >> n >> k;
    check.assign(n + 1, false);

    int i = 0;
    for (int j = 2; true; j++)
    {
        bool isBreak = false;
        if (check[j])
            continue;
        for (int m = j; m <= n; m += j)
        {
            if (check[m])
                continue;
            i++;
            if (i == k)
            {
                cout << m;
                isBreak = true;
                break;
            }
            check[m] = true;
        }
        if (isBreak)
            break;
    }
    return 0;
}