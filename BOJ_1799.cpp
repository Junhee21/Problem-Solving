// 21/10/26

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 비숍은 체스의 검은칸과 하얀칸이 서로 절대로 겹치지 않는다. -> 독립사건이다
// 따라서 검은칸과 하얀칸 두 경우를 DFS를 통해서 각각 최댓값을 구하고 마지막에 더해준다.
// 아래의 코드처럼 구분하지 않았을 때, 시간초과가 난다.

// vector<pair<int, int>> node;

// void Input(void)
// {
//     int n;
//     cin >> n;
//     for (int i=0; i<n; i++)
//     {
//         for (int j=0; j<n; j++)
//         {
//             int x;
//             cin >> x;
//             if (!x)
//                 continue;
//             int sum_rc = i+j;
//             int gap_rc = i-j+n-1;
//                 node.push_back({sum_rc, gap_rc});
//         }
//     }
// }

// int DFS(int i, long long sum_bit, long long gap_bit)
// {
//     if (i == (int)(node.size()))
//         return 0;
//     long long s = node[i].first;
//     long long g = node[i].second;
//     if (((1<<s) & sum_bit) || ((1<<g) & gap_bit))
//         return DFS(i+1, sum_bit, gap_bit);
//     int new_s = (1<<s)|sum_bit;
//     int new_g = (1<<g)|gap_bit;
//     return max(1+DFS(i+1, new_s, new_g), DFS(i+1, sum_bit, gap_bit));
// }

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     Input();
//     cout << DFS(0, 0, 0);
//     return 0;
// }

vector<pair<int, int>> node[2];

void Input(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            int x;
            cin >> x;
            if (!x)
                continue;
            int sum_rc = i+j;
            int gap_rc = i-j+n-1;
            if (sum_rc%2 == 0)
                node[0].push_back({sum_rc/2, gap_rc/2});
            else
                node[1].push_back({sum_rc/2, gap_rc/2});
        }
    }
}

int DFS(int i, int sum_bit, int gap_bit, int state)
{
    if (i == (int)(node[state].size()))
        return 0;
    int s = node[state][i].first;
    int g = node[state][i].second;
    if (((1<<s) & sum_bit) || ((1<<g) & gap_bit))
        return DFS(i+1, sum_bit, gap_bit, state);
    int new_s = (1<<s)|sum_bit;
    int new_g = (1<<g)|gap_bit;
    return max(1+DFS(i+1, new_s, new_g, state), DFS(i+1, sum_bit, gap_bit, state));
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Input();
    cout << DFS(0, 0, 0, 0)+DFS(0, 0, 0, 1);
    return 0;
}