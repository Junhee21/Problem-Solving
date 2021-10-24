// 21/10/24

#include <iostream>
using namespace std;

int n;
bool edge[100][100];

void Input(void)
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cin >> edge[i][j];
    }
}

void Solve(void)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (edge[j][i] && edge[i][k])
                    edge[j][k] = true;
            }
        }
    }
}

void Output(void)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<< edge[i][j] <<" ";
        cout << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solve();
    Output();
    return 0;
}