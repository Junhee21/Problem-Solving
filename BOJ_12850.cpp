// 22 / 1 / 14

#include <iostream>
#include <vector>
using namespace std;

const long long divided = 1000000007;
vector<vector<long long>> square;
vector<vector<long long>> matrix = {
    // 정보 , 전산, 미래, 신양, 환경, 진리, 학생, 형남  - 인접행렬
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}};

vector<vector<long long>> product(vector<vector<long long>> &a, vector<vector<long long>> &b)
{
    vector<vector<long long>> output(8, vector<long long>(8, 0));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            long long x = 0;
            for (int k = 0; k < 8; k++)
                x += (a[i][k] * b[k][j]);
            output[i][j] = (x % divided);
        }
    }
    return output;
}

void walk(int t)
{
    if (t == 1)
        return;
    walk(t / 2);
    square = product(square, square);
    if (t % 2 == 1)
        square = product(square, matrix);
}

int main(void)
{
    int n;
    cin >> n;
    square = matrix;
    walk(n);
    cout << square[0][0];
    return 0;
}