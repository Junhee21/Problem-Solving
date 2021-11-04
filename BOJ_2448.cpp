// 21/11/04

#include <iostream>
using namespace std;

bool entire[3072][6143];
bool star[3][5] = {{false, false, true, false, false}, {false, true, false, true, false},
                    {true, true, true, true, true}};

void Solve(int r, int c, int level)
{
    if (level == 3)
    {
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<5; j++)
                entire[r+i][c+j] = star[i][j];
        }
        return;
    }

    Solve(r, c+level/2, level/2);;
    Solve(r+level/2, c, level/2);
    Solve(r+level/2, c+level, level/2);
}

int main(void)
{
    int n;
    cin >> n;
    Solve(0, 0, n);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<2*n-1; j++)
        {
            if (entire[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout <<"\n";
    }
    return 0;
}