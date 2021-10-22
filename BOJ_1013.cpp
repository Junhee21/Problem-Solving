// 21/10/22

// (100+1+ | 01)+
#include <iostream>
#include <string>
using namespace std;

int answer = 0;
string s;

void DFS(int i, int first, int state)
{
    if ((int)s.size() == i)
    {
        if (state == 2)
            return;
        else if (state == 1)
            return;
        answer++;
        return;
    }
    
    if (state == 0)
    {
        if (s[i] == '1')
            DFS(i+1, i, 1);
        else
            DFS(i+1, i, 2);
    }
    else if (state == 2)
    {
        if (s[i] != '1')
            return;
        else
            DFS(i+1, i+1, 0);
    }
    else if (state == 1)
    {
        if (i - first <= 2)
        {
            if (s[i] != '0')
                return;
            else
                DFS(i+1, first, 1);
        }
        else
        {
            if (s[i] == '0')
                DFS(i+1, first, 1);
            else
                DFS(i+1, first, 3);
        }
    }
    else
    {
        if (s[i] == '1')
        {
            DFS(i+1, i, 1);
            DFS(i+1, first, 3);
        }
        else
            DFS(i+1, i, 2);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num;
    while (test_num--)
    {
        cin >> s;
        answer = 0;
        DFS(0, 0, 0);
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}