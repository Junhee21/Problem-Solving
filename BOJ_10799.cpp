// 22 / 1 / 1

#include <iostream>
using namespace std;

char arr[100000 + 1];

int main(void)
{
    cin >> arr;
    int x = 0;
    int answer = 0;
    bool check = true;
    for (int i = 0; true; i++)
    {
        if (!arr[i])
            break;
        else if (arr[i] == '(')
        {
            x++;
            check = true;
        }
        else
        {
            x--;
            if (check)
            {
                answer += x;
                check = false;
            }
            else
                answer++;
        }
    }
    cout << answer;
    return 0;
}