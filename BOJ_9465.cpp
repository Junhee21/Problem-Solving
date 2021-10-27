// 21/10/27

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sticker[3][100000];
int dp[100000][3];
int n;

void Input(void)
{
    cin >> n;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<n; j++)
        {
            dp[j][i] = -1;
            if (i==2)
                continue;
            cin >> sticker[i][j];
        }
    }
}

int Pick_sticker(int c, int state)
{
    if (c==n)
        return 0;

    if (dp[c][state]!=-1)
        return dp[c][state];

    vector<int> arr;
    for (int i=0; i<3; i++)
    {
        if (i==state)
            continue;
        arr.push_back(Pick_sticker(c+1, i));
        if (state!=2)
        {
            arr.back()+=sticker[state][c];
        }
    }
    return dp[c][state] = *max_element(arr.begin(), arr.end());
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        Input();
        vector<int> answer_list;
        for (int i=0; i<3; i++)
            answer_list.push_back(Pick_sticker(0,i));

        cout << *max_element(answer_list.begin(), answer_list.end()) << "\n";
    }

    return 0;
}