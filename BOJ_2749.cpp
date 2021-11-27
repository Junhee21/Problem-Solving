// 21/11/27

#include <iostream>
#include <vector>
using namespace std;

const long long divided = 1000000;
long long n;
vector<long long> ele = {1, 1, 1, 0};
vector<long long> matrix = {1, 0, 0, 1};

vector<long long> matrixProduct(vector<long long> a, vector<long long> b)
{
    vector<long long> output;
    output.push_back((a[0] * b[0] + a[1] * b[2]) % divided);
    output.push_back((a[0] * b[1] + a[1] * b[3]) % divided);
    output.push_back((a[2] * b[0] + a[3] * b[2]) % divided);
    output.push_back((a[2] * b[1] + a[3] * b[3]) % divided);
    return output;
}

int main(void)
{
    cin >> n;

    while (1)
    {
        if (n % 2 == 1)
            matrix = matrixProduct(matrix, ele);

        if (n == 1)
            break;
        n /= 2;
        ele = matrixProduct(ele, ele);
    }

    cout << matrix[2];
    return 0;
}