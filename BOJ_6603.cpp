// 21 / 12 / 16

#include <iostream>
#include <vector>
using namespace std;

vector<bool> check;
vector<int> arr;

void dfs(int level, int x, int num)
{
    if (level == 6)
    {
        for (int i = 0; i < num; i++)
        {
            if (check[i])
                cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = x; i < num; i++)
    {
        check[i] = true;
        dfs(level + 1, i + 1, num);
        check[i] = false;
    }
}

void solve(int num)
{
    check.assign(num, false);
    arr.assign(num, 0);

    for (int i = 0; i < num; i++)
        cin >> arr[i];

    dfs(0, 0, num);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
    int num;
    cin >> num;

    if (num == 0)
        break;
    
    solve(num);
    cout << "\n";
    }

    return 0;
}