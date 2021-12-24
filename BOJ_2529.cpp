// 21 / 12 / 24

#include <iostream>
#include <vector>
using namespace std;

int n;
bool isMax, isMin;
vector<bool> check(10, false);
vector<bool> arr;
vector<int> maxNum;
vector<int> minNum;

void dfsMax(int level)
{
    if (isMax)
        return;

    if (level == n + 1)
    {
        isMax = true;
        for (int i = 0; i < n + 1; i++)
            cout << maxNum[i];
        cout << "\n";
        return;
    }

    for (int i = 9; i >= 0; i--)
    {
        if (check[i])
            continue;
        if (level != 0)
        {
            if ((arr[level - 1]) && (maxNum.back() >= i))
                continue;
            if ((!arr[level - 1]) && (maxNum.back() <= i))
                continue;
        }

        check[i] = true;
        maxNum.push_back(i);
        dfsMax(level + 1);
        check[i] = false;
        maxNum.pop_back();
    }
}

void dfsMin(int level)
{
    if (isMin)
        return;

    if (level == n + 1)
    {
        isMin = true;
        for (int i = 0; i < n + 1; i++)
            cout << minNum[i];
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        if (check[i])
            continue;
        if (level != 0)
        {
            if ((arr[level - 1]) && (minNum.back() >= i))
                continue;
            if ((!arr[level - 1]) && (minNum.back() <= i))
                continue;
        }

        check[i] = true;
        minNum.push_back(i);
        dfsMin(level + 1);
        check[i] = false;
        minNum.pop_back();
    }
}

int main(void)
{
    cin >> n;
    arr.assign(n, false);

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '<')
            arr[i] = true;
    }

    dfsMax(0);
    dfsMin(0);

    return 0;
}