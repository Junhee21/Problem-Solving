// 21/11/21

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];

int abs(int num)
{
    if (num > 0)
        return num;
    else
        return -num;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int front = 0;
    int back = n-1;
    int sum = arr[front] + arr[back];
    int frontAnswer = 0;
    int backAnswer = n-1;

    while (front < back)
    {
        int temp = arr[front] + arr[back];
        if (abs(temp) < abs(sum))
        {
            sum = temp;
            frontAnswer = front;
            backAnswer = back;
        }
        if (temp > 0)
            back --;
        else
            front ++;
    }

    cout << arr[frontAnswer] << " " << arr[backAnswer];
    return 0;
}