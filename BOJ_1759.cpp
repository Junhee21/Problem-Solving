// 22 / 1 / 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> vowel = {'a', 'e', 'i', 'o', 'u'};
vector<bool> check;
vector<pair<char, bool>> alphabet;
int n, m;

void dfs(int index, int level, int vo, int co)
{
    if (level == n)
    {
        if ((vo < 1) || (co < 2))
            return;

        for (int i = 0; i < m; i++)
        {
            if (check[i])
                cout << alphabet[i].first;
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < m; i++)
    {
        check[i] = true;
        if (alphabet[i].second)
            dfs(i + 1, level + 1, vo + 1, co);
        else
            dfs(i + 1, level + 1, vo, co + 1);
        check[i] = false;
    }
}

int main(void)
{
    cin >> n >> m;
    check.assign(m, false);
    for (int i = 0; i < m; i++)
    {
        char x;
        cin >> x;
        bool isVowel = false;
        for (int i = 0; i < 5; i++)
        {
            if (x == vowel[i])
                isVowel = true;
        }
        alphabet.push_back({x, isVowel});
    }

    sort(alphabet.begin(), alphabet.end());

    dfs(0, 0, 0, 0);

    return 0;
}