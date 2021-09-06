//21 09 05

#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
using namespace std;

vector<int> course;
vector<int> before_node;
vector<int> dslr;
vector<int> answer;

void bfs(int start, int finish){
    course.clear();
    before_node.clear();
    dslr.clear();
    course.assign(10000, INF);
    before_node.assign(10000, INF);
    dslr.assign(10000, INF);
    course[start] = 0;
    before_node[start] = -1;

    queue<int>qu;
    qu.push(start);

    while(!qu.empty()){
        int node = qu.front();
        int cost = course[node];
        qu.pop();
        if (node==finish)
            break;
        if (course[node*2%10000] > cost+1){
            course[node*2%10000] = cost+1;
            before_node[node*2%10000] = node;
            dslr[node*2%10000] = 0;
            qu.push(node*2%10000);
        }
        if ((node==0)&&(course[9999] > cost+1)){
            course[9999] = cost+1;
            before_node[9999] = 0;
            dslr[9999] = 1;
            qu.push(9999);
        }
        if ((node!=0)&&(course[node-1] > cost+1)){
            course[node-1] = cost+1;
            before_node[node-1] = node;
            dslr[node-1] = 1;
            qu.push(node-1);
        }
        int do_left = (node%1000)*10 + node/1000;
        int do_right = (node/10) + (node%10)*1000;
        if (course[do_left] > cost+1){
            course[do_left] = cost+1;
            before_node[do_left] = node;
            dslr[do_left] = 2;
            qu.push(do_left);
        }
        if (course[do_right] > cost+1){
            course[do_right] = cost+1;
            before_node[do_right] = node;
            dslr[do_right] = 3;
            qu.push(do_right);
        }
    }
}

void Back_tracking(int finish){
    if (before_node[finish] != -1){
        answer.push_back(dslr[finish]);
        Back_tracking(before_node[finish]);
    }
}

int main(void){
    int t; cin>>t;
    while (t--){
        int a, b; cin>>a>>b;
        
        bfs(a, b);
        answer.clear();
        Back_tracking(b);

        for (int i=answer.size()-1; i>=0; i--){
            if (answer[i]==3)   cout<<"R";
            if (answer[i]==2)   cout<<"L";
            if (answer[i]==1)   cout<<"S";
            if (answer[i]==0)   cout<<"D";
        }
        cout<<endl;
    }
    return 0;
}