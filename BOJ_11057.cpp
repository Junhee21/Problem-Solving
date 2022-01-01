// 22 / 1 / 1

#include <iostream>
#include <vector>
using namespace std;

const int divided = 10007;
vector<int> arr(10, 1);

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            int x = 0;
            for (int k = 0; k <= j; k++)
                x += arr[k];
            arr[j] = (x % divided);
        }
    }

    int answer = 0;
    for (int i = 0; i < 10; i++)
        answer += arr[i];
    cout << answer % divided;
    return 0;
}