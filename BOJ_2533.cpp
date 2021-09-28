//21 09 28

// 잘못생각했다 아래 코드는 트리의 level 당 사이즈를 구한다.


// #include <iostream>
// #include <vector>
// using namespace std;
// const int MAX = 1000000 + 1;

// vector<int> edge[MAX];
// bool visited[MAX];

// int eary_num[2] = {0,0};
// int n;

// void How_many_early(int state, vector<int> list)
// {
//     vector<int> mist;
//     for (auto iter = list.begin(); iter != list.end(); iter++)
//     {
//         visited[*iter] = true;
//         eary_num[state]++;
//         for (auto iter1 = edge[*iter].begin(); iter1 != edge[*iter].end(); iter1++)
//         {
//             if (visited[*iter1])
//                 continue;
//             mist.push_back(*iter1);
//         }
//     }
//     if (mist.size())
//         How_many_early(1-state, mist);
// }

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>n;
//     for (int i=0; i<n-1; i++)
//     {
//         int a, b;
//         cin>>a>>b;
//         edge[a].push_back(b);
//         edge[b].push_back(a);
//     }

//     How_many_early(1, {1});

//     cout<<eary_num[0]<<" "<<eary_num[1];

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000 + 1;

vector<int> edge[MAX];
int dp[MAX][2];
int n;

void dfs(int node, int parent)
{
    for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
    {
        if (*iter == parent)
            continue;
        dfs (*iter, node);
    }

    dp[node][1] = 1;
    for (auto iter = edge[node].begin(); iter!=edge[node].end(); iter++)
    {
        if(*iter == parent)
            continue;
        dp[node][0] += dp[*iter][1];
        dp[node][1] += min(dp[*iter][1], dp[*iter][0]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1, -1);
    
    cout<<min(dp[1][0], dp[1][1]);

    return 0;
}