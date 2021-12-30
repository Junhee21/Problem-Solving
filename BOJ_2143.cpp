// 21 / 12 / 30

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;
long long answer;
vector<int> a;
vector<int> b;
vector<int> pickA;
vector<int> pickB;
vector<pair<int, int>> sortPickB;

void initList(vector<int> &newArr, vector<int> &arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        int x = 0;
        for (int j = i; j < length; j++)
        {
            x += arr[j];
            newArr.push_back(x);
        }
    }
    return;
}

int search(int x)
{
    int le = 0;
    int ri = sortPickB.size() - 1;
    while (le + 1 < ri)
    {
        int middle = (le + ri) / 2;
        if (sortPickB[middle].first < x)
            le = middle;
        else
            ri = middle;
    }

    if (sortPickB[le].first == x)
        return sortPickB[le].second;
    else if (sortPickB[ri].first == x)
        return sortPickB[ri].second;
    else
        return 0;
}

int main(void)
{
    cin >> t >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    b.assign(m, 0);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    initList(pickA, a, n);
    initList(pickB, b, m);

    sort(pickB.begin(), pickB.end());

    sortPickB.push_back({pickB.front(), 1});
    for (int i = 1; i < (int)pickB.size(); i++)
    {
        if (pickB[i] == sortPickB.back().first)
            sortPickB.back().second++;
        else
            sortPickB.push_back({pickB[i], 1});
    }

    for (auto iter = pickA.begin(); iter != pickA.end(); iter++)
    {
        int x = t - (*iter);
        answer += search(x);
    }

    cout << answer;
    return 0;
}