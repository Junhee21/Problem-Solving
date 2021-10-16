//21 10 16

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr1[200000];
int arr2[200000];
int dif_arr2[200000];
int text[400000];
int pattern[200000];

void Preprocess(void)
{
    int j=0;
    for (int i=1; i<n; i++)
    {
        while (j>0 && dif_arr2[i] != dif_arr2[j])
            j = pattern[j-1];
        if (dif_arr2[i] == dif_arr2[j])
            pattern[i] = ++j;
    }
}

bool Solve(void)
{
    int j=0;
    for (int i=0; i<2*n; i++)
    {
        while (j>0 && text[i] != dif_arr2[j])
            j = pattern[j-1];
        if (text[i] == dif_arr2[j])
        {
            j++;
            if (j==n)
                return true;
        }
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>n;
    for (int i=0; i<n; i++)
        cin>>arr1[i];
    for (int i=0; i<n; i++)
        cin>>arr2[i];
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    for (int j=0; j<2; j++)
    {
        for (int i=0; i<n-1; i++)
            text[j*n+i] = arr1[i+1] - arr1[i];
        text[j*n+n-1] = arr1[0]+360000-arr1[n-1];
    }
    for (int i=0; i<n-1; i++)
        dif_arr2[i] = arr2[i+1] - arr2[i];
    dif_arr2[n-1] = arr2[0]+360000-arr2[n-1];

    Preprocess();
    if (Solve())
        cout<<"possible";
    else
        cout<<"impossible";

    return 0;
}