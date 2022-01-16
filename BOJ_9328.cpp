// 22 / 01 / 01

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<bool> key(26);
vector<vector<char>> matrix;
vector<vector<pair<int, int>>> door;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string firstKey;

int n, m;

void input(void)
{
    cin >> n >> m;
    key.assign(26, false);
    matrix.assign(n + 2, vector<char>(m + 2, '.'));
    door.assign(26, vector<pair<int, int>>(0, {-1, -1}));

    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            matrix[i][j + 1] = str[j];
    }
    cin >> firstKey;
    if (firstKey[0] == '0')
        return;
    for (int i = 0; i < firstKey.size(); i++)
        key[firstKey[i] - 'a'] = true;
}

void search(int r, int c, int *ptr)
{
    matrix[r][c] = '!';
    for (int i = 0; i < 4; i++)
    {
        int r1 = r + dir[i].first;
        int c1 = c + dir[i].second;
        if ((r1 < 0) || (r1 > n + 1) || (c1 < 0) || (c1 > m + 1))
            continue;
        int node = matrix[r1][c1];
        if (node == '.')
            search(r1, c1, ptr);
        else if (node == '$')
        {
            (*ptr)++;
            search(r1, c1, ptr);
        }
        else if ((node >= 'a') && (node <= 'z'))
        {
            key[node - 'a'] = true;
            search(r1, c1, ptr);
            while (door[node - 'a'].size() != 0)
            {
                pair<int, int> nowDoor = door[node - 'a'].back();
                door[node - 'a'].pop_back();
                search(nowDoor.first, nowDoor.second, ptr);
            }
        }
        else if ((node >= 'A') && (node <= 'Z'))
        {
            if (key[node - 'A'])
                search(r1, c1, ptr);
            else
                door[node - 'A'].push_back({r1, c1});
        }
    }
}

int solve(void)
{
    int answer = 0;
    search(0, 0, &answer);
    return answer;
}

int main(void)
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        input();
        cout << solve() << "\n";
    }
    return 0;
}