// 22 / 2 / 7

#include <iostream>
using namespace std;

int main(void)
{
    int n, answer = 0;
    cin >> n;

    while (n--)
    {
        int students, apples;
        cin >> students >> apples;
        answer += (apples % students);
    }
    cout << answer;
    return 0;
}