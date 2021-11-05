// 21/11/05

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer;

struct trie
{
    trie* child[26];
    bool is_end = false;

    trie()
    {
        for (int i=0; i<26; i++)
            child[i] = nullptr;
    }

    void insert(string&str, int index)
    {
        if (index == str.size())
        {
            is_end = true;
            return;
        }

        if (child[str[index]-'a'] == nullptr)
        {
            trie*node = new trie();
            child[str[index] - 'a'] = node;
        }
        (*child[str[index]-'a']).insert(str, index+1);
    }

    void search(string&str, int index)
    {
        if (index == str.size())
        {
            if (is_end)
                answer++;
            return;
        }

        if (child[str[index]-'a'] == nullptr)
            return;
        (*child[str[index]-'a']).search(str, index+1);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    struct trie trie_string;
    while (n--)
    {
        string str;
        cin >> str;
        trie_string.insert(str, 0);
    }
    while (m--)
    {
        string str;
        cin >> str;
        trie_string.search(str, 0);
    }
    cout << answer;

    return 0;
}