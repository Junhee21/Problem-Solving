// 21/11/12

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<bool>> boolEdge(501, vector<bool>(501, false));
vector<int> lastYearRank(500, 0);
vector<int> lastYearNodeRank(501, 0);
vector<int> edge[501];
vector<int> parentNum(501, 0);
vector<int> output;

void input(){
    output.clear();
    cin >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        lastYearRank[i-1] = x;
        lastYearNodeRank[x] = i;
        edge[i].clear();
        parentNum[i]=0;
        for (int j=1; j<=n; j++){
            boolEdge[i][j] = false;
        }
    }
    cin >> m;
    while (m--){
        int a, b;
        cin >> a >> b;
        if (lastYearNodeRank[a] < lastYearNodeRank[b]){
            edge[b].push_back(a);
            parentNum[a]++;
        }
        else{
            edge[a].push_back(b);
            parentNum[b]++;
        }
        boolEdge[b][a] = true;
        boolEdge[a][b] = true;
    }

    for (int i=0; i<n; i++){
        int node1 = lastYearRank[i];
        for (int j=i+1; j<n; j++){
            int node2 = lastYearRank[j];
            if (boolEdge[node1][node2])
                continue;

            edge[node1].push_back(node2);
            parentNum[node2]++;
        }
    }
}

void solve(void){
    queue<int> q;
    for (int i=1; i<=n; i++){
        if (parentNum[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        if (q.size()>1){
            cout << "?\n";
            return;
        }

        int x = q.front();
        output.push_back(x);
        q.pop();
        for (auto iter = edge[x].begin(); iter!=edge[x].end(); iter++){
            parentNum[*iter]--;
            if (parentNum[*iter] == 0){
                q.push(*iter);
            }
        }
    }

    if (output.size()!=n){
        cout << "IMPOSSIBLE\n";
    }
    else{
        for (int i=0; i<n; i++){
            cout << output[i] <<" ";
        }
        cout <<"\n";
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--){
        input();
        solve();
    }
    return 0;
}