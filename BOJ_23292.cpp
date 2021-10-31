// 21/10/30

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> date;
int answer,answer_index, birth, n;

void Input(void)
{
    cin >> birth;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        date.push_back(x);
    }
}

int sum(int index)
{
    int x = date[index];
    int b = birth;
    int a = 1;
    int temp = 0;

    for (int i=0; i<2; i++)
    {
        temp += ((x%10-b%10)*(x%10-b%10));
        x/=10;
        b/=10;
    }
    a *= temp;
    temp = 0;
    for (int i=0; i<2; i++)
    {
        temp += ((x%10-b%10)*(x%10-b%10));
        x/=10;
        b/=10;
    }
    a *= temp;
    temp = 0;
    for (int i=0; i<4; i++)
    {
        temp += ((x%10-b%10)*(x%10-b%10));
        x/=10;
        b/=10;
    }
    a *= temp;
    return a;
}

void Solve(void)
{
    sort(date.begin(), date.end());
    for (int i=0; i<n; i++)
    {
        int x = sum(i);
        if (x>answer)
        {
            answer = x;
            answer_index = i;
        }
    }
    cout << date[answer_index];
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Solve();
    return 0;
}