// 21/10/24

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool check[10];
int answer = 987654321;
int target=0, level=1;

void DFS(int num, int lev)
{
    answer = min(answer, lev + abs(num-target));
    if (lev == level)
        return;

    for (int i=0; i<10; i++)
    {
        if (check[i])
            continue;
        DFS(num*10+i, lev+1);
    }
}

int main(void)
{
    cin >> target;

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        check[x] = true;
    }
    
    int temp = target;
    while (temp > 0)
    {
        temp /= 10;
        level ++;
    }
    answer = min(answer, abs(target-100));

    for (int i=0; i<10; i++)
    {
        if (check[i])
            continue;
        DFS(i, 1);
    }

    cout << answer;
    return 0;
}