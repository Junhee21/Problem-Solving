//21 10 13

#include <iostream>
using namespace std;

int arr[257];
int n, m, b;
int result = 987654321, result_height = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> b;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            int x;
            cin >> x;
            arr[x]++;
        }
    }
    int low = 500, high = -1;
    for (int i=0; i<=256; i++)
    {
        if (arr[i])
        {
            if (i>high)
                high = i;
            if (i<low)
                low = i;
        }
    }

    for (int i=low; i<=high; i++)
    {
        int t = b;
        int temp_result = 0;
        for (int j=high; j>=low; j--)
        {
            if (j>=i)
            {
                t += arr[j]*(j-i);
                temp_result += 2*arr[j]*(j-i);
            }
            else
            {
                t -= arr[j]*(i-j);
                temp_result += arr[j]*(i-j);
                if (t<0)
                {
                    temp_result = 987654321;
                    break;
                }
            }
        }
        if (temp_result <= result)
        {
            result = temp_result;
            result_height = i;
        }
    }

    cout << result << " " << result_height;
    return 0;
}