// 21/11/12

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> parentNum;
vector<vector<int>> edge;

void solve(){
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (parentNum[i] == 0){
            q.push(i);
        }
    }

    while (!q.empty()){
        int now = q.front();
        cout << now <<" ";
        q.pop();
        for (auto iter=edge[now].begin(); iter!=edge[now].end(); iter++){
            parentNum[*iter]--;
            if (parentNum[*iter] == 0){
                q.push(*iter);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    parentNum.assign(n+1, 0);
    edge.assign(n+1, vector<int>(0,0));
    while (m--)
    {
        int a, b;
        cin >> a>> b;
        edge[a].push_back(b);
        parentNum[b]++;
    }

    solve();
    return 0;
}