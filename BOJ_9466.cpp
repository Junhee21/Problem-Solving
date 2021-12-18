// 21 / 12 / 18

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr;
vector<bool> visited;
queue<int> q;
int n, answer;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int testcase;
    cin >> testcase;

    while (testcase--)
    {
        answer = 0;
        cin >> n;
        arr.assign(n + 1, 0);
        visited.assign(n + 1, false);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;
            q.push(i);

            int node = arr[i];

            while (!visited[node])
            {
                visited[node] = true;
                q.push(node);
                node = arr[node];
            }

            while (!q.empty())
            {
                if (q.front() == node)
                {
                    while (!q.empty())
                    {
                        q.pop();
                    }
                    break;
                }

                answer++;
                q.pop();
            }
        }

        cout << answer << "\n";
    }
    return 0;
}