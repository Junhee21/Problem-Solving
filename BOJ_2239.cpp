// 21/11/22

#include <iostream>
#include <vector>
using namespace std;

int matrix[9][9];
bool firstAnswer = false;

void DFS(int num)
{
    if (firstAnswer)
        return;

    if (num == 81)
    {
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
                cout << matrix[i][j];
            cout << "\n";
        }
        firstAnswer = true;
        return;
    }

    int r = num/9;
    int c = num%9;
    
    if (matrix[r][c] == 0)
    {
        vector<bool> check(10, false);
        for (int i=0; i<9; i++)
        {
            check[matrix[r][i]] = true;
            check[matrix[i][c]] = true;
            check[matrix[(r/3)*3 + (i/3)][(c/3)*3 + (i%3)]] = true;
        }
        for (int i=1; i<=9; i++)
        {
            if (!check[i])
            {
                matrix[r][c] = i;
                DFS(num+1);
                matrix[r][c] = 0;
            }
        }
    }
    else
    {
        DFS(num + 1);
    }
}

int main(void)
{
    for (int i=0; i<9; i++)
    {
        int arr;
        cin >> arr;
        for (int j=8; j>=0; j--)
        {
            matrix[i][j] = arr % 10;
            arr /= 10;
        }
    }

    DFS(0);

    return 0;
}