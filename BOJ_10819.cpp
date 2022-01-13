// 22 / 1 / 13

#include <iostream>
#include <vector>
using namespace std;

int n, answer;
vector<int> arr;
vector<bool> check;
vector<int> solveArr;

int gapSum()
{
    int output = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x = solveArr[i] - solveArr[i + 1];
        if (x > 0)
            output += x;
        else
            output += (-x);
    }
    return output;
}

void dfs(int level)
{
    if (level == n)
    {
        int x = gapSum();
        if (x > answer)
            answer = x;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i])
            continue;
        check[i] = true;
        solveArr.push_back(arr[i]);
        dfs(level + 1);
        check[i] = false;
        solveArr.pop_back();
    }
}

int main(void)
{
    cin >> n;
    arr.assign(n, 0);
    check.assign(n, false);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dfs(0);
    cout << answer;
    return 0;
}