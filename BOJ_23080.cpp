//21 10 03

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    string S;
    cin>>k>>S;

    for (int i=0; i<S.size(); i+=k)
        cout<<S[i];

    return 0;
}