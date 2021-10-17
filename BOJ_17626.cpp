//21 10 17

#include <iostream>
#include <vector>
using namespace std;

vector<int> base;
bool check[50000+1];
int n;

int dfs(vector<int>para, int num)
{
    vector<int> arr;
    for (auto iter = base.begin(); iter!=base.end(); iter++)
    {
        for (auto iter2 = para.begin(); iter2!=para.end(); iter2++)
        {
            if ((*iter)+(*iter2)>50000  || check[(*iter)+(*iter2)])
                continue;
            if ((*iter)+(*iter2)==n)
                return num;
            check[(*iter)+(*iter2)] = true;
            arr.push_back((*iter)+(*iter2));
        }

    }
    return dfs(arr, num+1);
}

int Solve(void)
{
    for (int i=1; i*i<=50000; i++)
    {
        base.push_back(i*i);
        check[i*i] = true;
        if (i*i == n)
            return 1;
    }

    return dfs(base, 2);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << Solve();

    return 0;
}