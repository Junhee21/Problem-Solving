// 21/11/07

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, answer;
bool check[26];
vector<int> arr;

void solve(int bit)
{
    int nowAnswer = 0;
    for (int i=0; i<n; i++)
    {
        int num = arr[i];
        if (bit == (num|bit))
            nowAnswer++;
    }
    if (nowAnswer>answer)
        answer = nowAnswer;
}

void DFS(int level, int bit, int nowNode)
{
    if (level == m-5)
    {
        solve(bit);
        return;
    }

    for (int i=nowNode+1; i<26; i++)
    {
        if (check[i] || bit&(1<<i))
            continue;
        
        int new_bit = (bit|(1<<i));
        DFS(level+1, new_bit, i);
    }
}

void input()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        string str;
        cin >> str;
        int bit = 0;
        for (auto iter=str.begin()+4; iter!=str.end()-4; iter++)
        {
            if (check[(*iter)-'a'])
                continue;
            bit |= (1<<((*iter)-'a'));
        }
        arr.push_back(bit);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    check['a'-'a'] = true;
    check['c'-'a'] = true; 
    check['i'-'a'] = true; 
    check['n'-'a'] = true; 
    check['t'-'a'] = true; 

    input();

    if (m>=5)
        DFS(0, 0, -1);

    cout << answer;

    return 0;
}