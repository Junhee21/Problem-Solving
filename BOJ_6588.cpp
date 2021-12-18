// 21 / 12 / 18

#include <iostream>
#include <vector>
using namespace std;

vector<int> prime;
vector<bool> check(1000000, false);
vector<bool> isPrime(1000000, false);

void searchPrime(void)
{
    for (int i = 2; i < 1000000; i++)
    {
        if (check[i])
            continue;
        for (int j = i; j < 1000000; j += i)
            check[j] = true;
        prime.push_back(i);
        isPrime[i] = true;
    }
}

void solve(int n)
{
    for (int i = 1; i < (int)prime.size(); i++)
    {
        if (n - prime[i] <= 0)
        {
            cout << "Goldbach's conjecture is wrong.\n";
            return;
        }
        if (isPrime[n - prime[i]])
        {
            cout << n << " = " << prime[i] << " + " << n - prime[i] << "\n";
            return;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    searchPrime();

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        solve(n);
    }

    return 0;
}