// 21/11/22

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ABS(long long num)
{
    if (num > 0)
        return num;
    else
        return -num;
}

vector<long long> arr;
int n;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());

    long long answer = 9876543210;
    vector<int> answerList(3, 0);

    for (int i = 0; i < n; i++)
    {
        int first = 0;
        int last = n - 1;
        int another = i;
        while (first < last)
        {
            long long sum = (arr[first] + arr[last] + arr[another]);
            long long absSum = ABS(sum);

            if (absSum < answer)
            {
                if ((another != first) && (another != last))
                {
                    answer = absSum;
                    answerList[0] = arr[first];
                    answerList[1] = arr[last];
                    answerList[2] = arr[another];
                }
            }

            if (sum > 0)
                last--;
            else
                first++;
        }
    }

    sort(answerList.begin(), answerList.end());

    cout << answerList[0] << " " << answerList[1] << ' ' << answerList[2];
    return 0;
}