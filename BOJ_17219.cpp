// 21/10/21

#include <iostream>
#include <string>
#include <map>
using namespace std;

int n, m;
map<string, string>web_pass;

void Input(void)
{
    while (n--)
    {
        string website, password;
        cin >> website >> password;
        web_pass.insert({website, password});
    }
}

void Output(void)
{
    while (m--)
    {
        string whatPass;
        cin >> whatPass;
        cout<<web_pass[whatPass]<<"\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    Input();
    Output();
    return 0;
}