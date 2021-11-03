// 21/11/03

#include <iostream>
using namespace std;

void Print_star(int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<i; j++)
            cout << " ";
        for (int j=i; j<n; j++)
            cout << "*";
        cout << "\n";
    }
}

int main(void)
{
    int n;
    cin >> n;
    Print_star(n);
    return 0;
}