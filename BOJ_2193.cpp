// 21/11/11

#include <iostream>
using namespace std;

int n;

void DFS(pair<long long, long long> num, int level)
{
    if (level == n)
    {
        cout << num.first+num.second;
        return;
    }

    DFS(make_pair(num.first+num.second, num.first), level+1);
}

int main(void)
{
    cin >> n;
    DFS({0, 1}, 1);
    return 0;
}