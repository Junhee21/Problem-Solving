// 21 / 12 / 31

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, s;
long long answer;
vector<int> arr;
map<int, int> m;

void dfsLeft(int level, int sum)
{
    if (level == arr.size() / 2)
    {
        return;
    }

    m[sum + arr[level]]++;
    dfsLeft(level + 1, sum + arr[level]);
    dfsLeft(level + 1, sum);
}

void dfsRight(int level, int sum)
{
    if (level == arr.size())
        return;

    int x = sum + arr[level];
    answer += m[s - x];
    dfsRight(level + 1, x);
    dfsRight(level + 1, sum);
}

int main(void)
{
    cin >> n >> s;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dfsLeft(0, 0);
    answer += m[s];
    m[0]++;
    dfsRight(arr.size() / 2, 0);

    cout << answer;

    return 0;
}