// 21/11/19

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    cin >> str;

    string output = "";
    for (int i=0; i<(int)str.size(); i++)
    {
        if (i%10 == 0 && i/10!=0)
        {
            cout << output << "\n";
            output = "";
        }
        output += str[i];
    }
    cout << output;

    return 0;
}