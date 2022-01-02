// 22 / 1 / 3

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> check;
queue<int> q;

int main(void)
{
    int n;
    cin >> n;
    check.assign(n + 1, 0);
    q.push(n);

    while (q.front() != 1)
    {
        int x = q.front();
        q.pop();
        if ((x % 3 == 0) && (check[x / 3] == 0))
        {
            check[x / 3] = 1;
            q.push(x / 3);
        }
        if ((x % 2 == 0) && (check[x / 2] == 0))
        {
            check[x / 2] = 2;
            q.push(x / 2);
        }
        if ((x > 1) && (check[x - 1] == 0))
        {
            check[x - 1] = 3;
            q.push(x - 1);
        }
    }

    vector<int> answer;
    int x = 1;
    int num = 0;
    while (1)
    {
        answer.push_back(x);
        if (x == n)
            break;
        if (check[x] == 1)
            x *= 3;
        else if (check[x] == 2)
            x *= 2;
        else
            x += 1;
        num++;
    }
    cout << num << "\n";
    for (int i = (int)answer.size() - 1; i >= 0; i--)
        cout << answer[i] << " ";
    return 0;
}