// 21/10/29

#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, int> arr[26];
vector<int> check;
bool num[10];
int answer;

void Input(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int chiper = 1;
        for (auto iter=s.rbegin(); iter!=s.rend(); iter++)
        {
            int x = (*iter)-'A';
            if (arr[x].first == 0)
                check.push_back(x);
            arr[x].first += chiper;
            chiper *= 10;
        }
    }
}

void DFS(int level)
{
    if (level == (int)check.size())
    {
        int data = 0;
        for (int i=0; i<(int)check.size(); i++)
            data += (arr[check[i]].first*arr[check[i]].second);
        if (data > answer)
            answer = data;
        return;
    }
    for (int i=0; i<10; i++)
    {
        if (num[i])
            continue;
        arr[check[level]].second = i;
        num[i] = true;
        DFS(level+1);
        num[i] = false;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    DFS(0);
    cout << answer;
    return 0;
}