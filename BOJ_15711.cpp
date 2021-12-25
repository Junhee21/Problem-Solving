// 21 / 12 / 25

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2000000 + 1;
vector<bool> check(MAX, false);
vector<int> prime;

bool solve(long long x, long long y)
{
    if ((x + y) % 2 == 0)
    {
        if (x + y == 2)
            return false;
        return true;
    }

    if (x + y == 3)
        return false;
        
    for (int i = 0; i < (int)prime.size(); i++)
    {
        if ((x + y - 2) == prime[i])
            return true;
        if ((x + y - 2) % prime[i] == 0)
            return false;
    }

    return true;
}

void initPrime()
{
    for (int i = 2; i < MAX; i++)
    {
        if (check[i])
            continue;
        prime.push_back(i);
        for (int j = 2 * i; j < MAX; j += i)
            check[j] = true;
    }
}

int main(void)
{
    int testCase;
    cin >> testCase;

    initPrime();
    while (testCase--)
    {
        long long x, y;
        cin >> x >> y;
        if (solve(x, y))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}