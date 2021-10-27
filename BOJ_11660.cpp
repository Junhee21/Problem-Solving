// 21/10/27

#include <iostream>
using namespace std;

int matrix[1025][1025];
long long sum_matrix[1025][1025];
int n, m;


void Init_matrix(void)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            sum_matrix[i][j] = (sum_matrix[i-1][j]+sum_matrix[i][j-1]-sum_matrix[i-1][j-1]+matrix[i][j]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
            cin >> matrix[i][j];
    }
    Init_matrix();
    while (m--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum_matrix[x2][y2]-sum_matrix[x2][y1-1]-sum_matrix[x1-1][y2]+sum_matrix[x1-1][y1-1]<<"\n";
    }
    return 0;
}