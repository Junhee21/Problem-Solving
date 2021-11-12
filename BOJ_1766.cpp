// 21/11/12

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> edge;
vector<int> parentNum;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    edge.assign(n+1, vector<int>(0, 0));
    parentNum.assign(n+1, 0);

    while (m--){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        parentNum[b]++;
    }

    priority_queue<int> q;
    for (int i=1; i<=n; i++){
        if (parentNum[i] == 0){
            q.push(-i);
        }
    }

    while (!q.empty()){
        int x = -q.top();
        q.pop();
        cout << x << " ";

        for (auto iter=edge[x].begin(); iter!=edge[x].end(); iter++){
            parentNum[*iter]--;
            if (parentNum[*iter] == 0){
                q.push(-(*iter));
            }
        }
    }

    return 0;
}