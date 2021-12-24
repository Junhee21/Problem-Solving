// 21 / 12 / 16

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
bool answerCheck;

bool checkSeries(int level) // now arr.size() == level+1
{
    bool allCheck = true;
    for (int i = 1; i <= (level / 2 + level % 2); i++)
    {
        bool partialCheck = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[level + 1 - 2 * i + j] != arr[level + 1 - i + j])
            {
                partialCheck = true;
                break;
            }
        }
        if (!partialCheck)
        {
            allCheck = false;
            break;
        }
    }
    return allCheck;
}

void dfs(int level)
{
    if (answerCheck)
        return;

    if (level == n)
    {
        answerCheck = true;
        for (int i = 0; i < n; i++)
            cout << arr[i];
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        arr.push_back(i);
        if (checkSeries(level))
            dfs(level + 1);
        arr.pop_back();
    }
}

int main(void)
{
    cin >> n;
    dfs(0);

    return 0;
}