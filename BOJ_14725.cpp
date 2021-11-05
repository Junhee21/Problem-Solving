// 21/10/25

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct trie
{
    map<string, trie*> child;

    void insert_child(vector<string>&s, int index)
    {
        if (index == s.size())
            return;
        if (!child.count(s[index]))
        {
            trie*trie_ptr = new trie();
            child.insert({s[index], trie_ptr});
        }
        (*child[s[index]]).insert_child(s, index+1);
    }

    void search(int level)
    {
        for (auto iter = child.begin(); iter != child.end(); iter++)
        {
            for (int i=0; i<level; i++)
                cout << "--";
            cout << iter->first<<"\n";
            (*iter->second).search(level+1);
        }
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    struct trie ant;
    while (T--)
    {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i=0; i<n; i++)
            cin >> s[i];
        ant.insert_child(s, 0);
    }

    ant.search(0);

    return 0;
}