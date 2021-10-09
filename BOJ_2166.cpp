//21 10 09

#include <iostream>
using namespace std;

int n;
double arr[10000][2];
double result;

double Find_triangle(int node1, int node2)
{
    double node1_x = arr[node1][0] - arr[0][0];
    double node1_y = arr[node1][1] - arr[0][1];
    double node2_x = arr[node2][0] - arr[0][0];
    double node2_y = arr[node2][1] - arr[0][1];

    return (node1_x*node2_y)-(node1_y*node2_x);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed;
    cout.precision(1);

    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i][0]>>arr[i][1];

    for (int i=1; i<n-1; i++)
        result += Find_triangle(i, i+1);

    result /= 2;

    if (result < 0)
        cout<<(-1)*result;
    else
        cout<<result;

    return 0;
}