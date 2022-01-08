// 22 / 1 / 8

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, answer;
vector<int> arr;
vector<int> check;
queue<int> q;

int main(void)
{
    cin >> n;
    arr.assign(n + 1, 0);
    check.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        if (check[i] > 0)
            continue;
        int x = i;
        while (check[x] == 0)
        {
            check[x] = 1;
            q.push(x);
            x = arr[x];
        }
        while (!q.empty())
        {
            if (q.front() == x)
                break;
            check[q.front()] = 2;
            q.pop();
        }
        answer += q.size();
        while (!q.empty())
            q.pop();
    }

    cout << answer << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (check[i] == 1)
            cout << i << "\n";
    }
    return 0;
}