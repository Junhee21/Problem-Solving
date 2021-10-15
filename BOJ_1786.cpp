//21 10 15

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string t;
string p;
vector<int> pre_p;
vector<int> result;

void Preprocess(void)
{
    int n = (int)p.size();
    int j = 0;
    pre_p.assign(n, 0);

    for (int i=1; i<n; i++)
    {
        while(j>0 && p[i] != p[j])
            j = pre_p[j-1];
        if (p[i] == p[j])
            pre_p[i] = ++j;
    }
}

void KMP(void)
{
    int n = (int)t.size();
    int m = (int)p.size();
    int j = 0;

    for (int i=0; i<n; i++)
    {
        while(j>0 && t[i] != p[j])
        {
            j = pre_p[j-1];
        }
        if (t[i]==p[j])
        {
            j++;
            if (j == m)
            {
                result.push_back(i-m+1);
                j=pre_p[j-1];
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, t);
    getline(cin, p);

    Preprocess();
    KMP();

    int result_size = (int)result.size();
    cout << result_size << "\n";
    for (int i=0; i<result_size; i++)
        cout<< result[i]+1 << " ";

    return 0;
}