// 21/11/07

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> parent;
vector<vector<int>> partypeople;

int findParent(int num)
{
    if (parent[num] == num)
        return num;

    return parent[num] = findParent(parent[num]);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    parent.assign(n+1, 0);
    partypeople.assign(m, vector<int>(0, 0));
    for (int i=1; i<=n; i++)
    {
        parent[i] = i;
    }

    int whoKnow = 0;
    int knowTrue;
    cin >> knowTrue;
    for (int i=0; i<knowTrue; i++)
    {
        int x;
        cin >> x;

        if (i==0)
            whoKnow = x;

        parent[x] = whoKnow;
    }

    for (int i=0; i<m; i++)
    {
        int parent_1;
        int numParty;
        cin >> numParty;
        for (int j=0; j<numParty; j++)
        {
            int x;
            cin >> x;
            partypeople[i].push_back(x);
            if (j==0)
                parent_1 = findParent(x);
            else
            {
                int parent_2 = findParent(x);
                parent[parent_2]= parent_1;
            }
        }
    }

    for (int i=1; i<=n ;i++)
        parent[i] = findParent(i);

    int answer = 0;
    int parent_know = parent[whoKnow];
    for (int i=0; i<m; i++)
    {
        if (parent[partypeople[i][0]] != parent_know)
            answer ++;
    }
    cout << answer;

    return 0;
}