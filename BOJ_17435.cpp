// 21/11/16

#include <iostream>
#include <vector>
using namespace std;

int n, q;
const int maxDepth = 19;
vector<vector<int>> parent;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    parent.assign(n+1, vector<int>(maxDepth, 0));
    for (int i=1; i<=n; i++)
        cin >> parent[i][0];

    for (int i=1; i<maxDepth; i++)
    {
        for (int j=1; j<=n; j++)
            parent[j][i] = parent[parent[j][i-1]][i-1];
    }

    cin >> q;
    while (q--)
    {
        int degree, num;
        cin >> degree >> num;

        int step = 0;
        while (1)
        {
            if (degree % 2 == 1)
                num = parent[num][step];
            if (degree == 1)
            {
                cout << num <<"\n";
                break;
            }
            degree/=2;
            step++;
        }
    }

    return 0;
}