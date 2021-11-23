// 21/11/23

#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
bool check[9];
bool answerCheck = false;

void DFS(int index, int level, int sum)
{
    if (answerCheck)
        return;

    if ((level == 7) && (sum == 100))
    {
        for (int i = 0; i < 9; i++)
        {
            if (check[i])
                cout << arr[i] << "\n";
        }
        answerCheck = true;
        return;
    }

    for (int i = index; i < 9; i++)
    {
        check[i] = true;
        DFS(i + 1, level + 1, sum + arr[i]);
        check[i] = false;
    }
}

int main(void)
{
    for (int i = 0; i < 9; i++)
        cin >> arr[i];

    sort(arr, arr + 9);

    DFS(0, 0, 0);

    return 0;
}