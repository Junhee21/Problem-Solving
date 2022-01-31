// 22 / 1 / 31

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> check(10 * 10 * 10 * 10, false);
vector<int> clockNum;

void init(void)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                for (int m = 1; m <= 9; m++)
                {
                    if (check[i * 1000 + j * 100 + k * 10 + m])
                        continue;
                    vector<int> arr = {
                        i * 1000 + j * 100 + k * 10 + m,
                        j * 1000 + k * 100 + m * 10 + i,
                        k * 1000 + m * 100 + i * 10 + j,
                        m * 1000 + i * 100 + j * 10 + k};
                    for (int a = 0; a < 4; a++)
                        check[arr[a]] = true;
                    clockNum.push_back(*min_element(arr.begin(), arr.end()));
                }
            }
        }
    }
}

int main(void)
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    init();
    sort(clockNum.begin(), clockNum.end());
    vector<int> arr = {
        a * 1000 + b * 100 + c * 10 + d,
        b * 1000 + c * 100 + d * 10 + a,
        c * 1000 + d * 100 + a * 10 + b,
        d * 1000 + a * 100 + b * 10 + c};
    int minNum = *min_element(arr.begin(), arr.end());

    for (int i = 0; true; i++)
    {
        if (clockNum[i] == minNum)
        {
            cout << i + 1;
            break;
        }
    }
    return 0;
}