// 21/10/20

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dance;
int dp[100001][1<<5];
int dance_size;

int DDR(int state1, int state2, int index)
{
    if (index == dance_size)
        return 0;

    if (dp[index][(1<<state1)|(1<<state2)])
        return dp[index][(1<<state1)|(1<<state2)];

    int button = dance[index];
    if (state1 == button || state2 == button)
        return dp[index][(1<<state1)|(1<<state2)] = DDR(state1, state2, index+1)+1;

    if (state1 == state2)
        return dp[index][(1<<state1)|(1<<state2)] = DDR(state1, button, index+1)+2;

    vector<int> arr;
    if (state1==0)
        arr.push_back(DDR(button, state2, index+1) + 2);
    else if ((state1-button)%2 == 0)
        arr.push_back(DDR(button, state2, index+1) + 4);
    else
        arr.push_back(DDR(button, state2, index+1) + 3);
    if (state2==0)
        arr.push_back(DDR(button, state1, index+1) + 2);
    else if ((state2-button)%2 == 0)
        arr.push_back(DDR(button, state1, index+1) + 4);
    else
        arr.push_back(DDR(button, state1, index+1) + 3);
    return dp[index][(1<<state1)|(1<<state2)] = *min_element(arr.begin(), arr.end());
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while (1)
    {
        int x;
        cin >> x;
        if (x == 0)
            break;
        dance.push_back(x);
    }
    dance_size = (int)dance.size();
    cout << DDR(0,0,0) ;

    return 0;
}