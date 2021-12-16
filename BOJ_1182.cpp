// 21 / 12 / 16

#include <iostream>
#include <vector>
using namespace std;

int n, s, answer;
vector<int> arr;

void dfs(int minNum, int level, int maxDepth, int sum)
{
    if (level == maxDepth)
    {
        if (sum == s)
            answer++;
        return;
    }

    for (int i = minNum; i < n; i++)
        dfs(i + 1, level + 1, maxDepth, sum + arr[i]);
}

int main(void)
{
    cin >> n >> s;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
        dfs(0, 0, i, 0);

    cout << answer;

    return 0;
}