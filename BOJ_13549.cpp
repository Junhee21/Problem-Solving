// 21/10/28

#include <iostream>
#include <queue>
using namespace std;

int arr[100000+1];

int Search_sister(int subin, int sister)
{
    for (int i=0; i<=100000; i++)
        arr[i] = -1;

    arr[subin] = 0;
    queue<int> q;
    q.push(subin);

    while (1)
    {
        int x = q.front();
        q.pop();
        for (int i=x; i<=100000; i*=2)
        {
            if (i==sister)
                return arr[x];
            if (i > 0 && arr[i-1]==-1)
            {
                arr[i-1] = arr[x]+1;
                q.push(i-1);
            }
            if (i < 100000 && arr[i+1]==-1)
            {
                arr[i+1] = arr[x]+1;
                q.push(i+1);
            }
            if (i==0)
                break;
        }
    }
}

int main(void)
{
    int subin, sister;
    cin >> subin >> sister;
    cout << Search_sister(subin, sister);
    return 0;
}