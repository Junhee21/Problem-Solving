// 22 / 2 / 6

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> answer;

int main(void)
{
    cin >> n;
    for (int i = n / 2; i <= n; i++)
    {
        vector<int> arr;
        arr.push_back(n);
        arr.push_back(i);
        while (arr[arr.size() - 2] - arr[arr.size() - 1] >= 0)
            arr.push_back(arr[arr.size() - 2] - arr[arr.size() - 1]);
        if (arr.size() > answer.size())
            answer = arr;
    }
    cout << answer.size() << "\n";
    for (int i = 0; i < (int)answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}