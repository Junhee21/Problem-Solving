// 21 / 12 / 16

#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main(void)
{
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++)
    {
        arr.push_back(i+1);
    }

    cout << "<";

    int i = 0;

    while (1)
    {
        if ((int)arr.size() == i+1)
        {
            cout << arr.back() <<">";
            break;
        }
        if (i % k == k-1)
            cout << arr[i] <<", ";
        else
            arr.push_back(arr[i]);
        i ++;
    }
    
    return 0;
}