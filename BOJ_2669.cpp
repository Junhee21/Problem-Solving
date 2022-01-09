// 22 / 1 / 9

#include <iostream>
using namespace std;

bool check[100][100];
int answer;

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < c; i++)
        {
            for (int j = b; j < d; j++)
                check[i][j] = true;
        }
    }

    for (int i = 1; i < 100; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            if (check[i][j])
                answer++;
        }
    }
    cout << answer;
    return 0;
}