// 21/11/11

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    while (1)
    {
        getline(cin, str);
        if (cin.eof())
            break;
        cout << str;
    }
    return 0;
}