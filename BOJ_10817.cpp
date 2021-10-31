// 21/11/01

#include <iostream>
using namespace std;

int main(void)
{
    int arr[3];
    for (int i=0; i<3; i++)
        cin >> arr[i];
    for (int i=0; i<=1; i++)
    {
        int max_index = i;
        int max_num = arr[i];
        for (int j=i+1; j<=2; j++)
        {
            if (arr[j] > max_num)
            {
                max_num = arr[j];
                max_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = max_num;
        arr[max_index] = temp;
    }
    cout << arr[1];
    return 0;
}