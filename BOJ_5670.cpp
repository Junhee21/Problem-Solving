// 21/11/05

#include <iostream>
#include <string>
using namespace std;

struct trie
{
    trie* child[26];

    bool isEnd = false;
    int howType = 0;
    int howChild = 0;

    trie()
    {
        for (int i=0; i<26; i++)
            child[i] = nullptr;
    }
    ~trie()
    {
        for (int i=0; i<26; i++)
        {
            if (child[i])
                delete child[i];
        }
    }

    void insert(string&str, int index)
    {
        if (index == str.size())
        {
            isEnd = true;
            return;
        }
        
        int iter = str[index]-'a';
        if (!child[iter])
        {
            trie*ch = new trie();
            child[iter] = ch;
            howChild ++;
        }
        howType ++;
        (*child[iter]).insert(str, index+1);
    }

    void search(int index, int*num_ptr)
    {
        if (isEnd || howChild!=1)
            *num_ptr += howType;
        
        for (int i=0; i<26; i++)
        {
            if (!child[i])
                continue;
            (*child[i]).search(index+1, num_ptr);
        }
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed;
    cout.precision(2);

    int n;
    while (1)
    {
        cin >> n;
        if (cin.eof())
            break;

        struct trie dictionary;
        dictionary.isEnd = true;
        for (int i=0; i<n; i++)
        {
            string str;
            cin >> str;
            dictionary.insert(str, 0);
        }

        int num = 0;
        dictionary.search(0, &num);
        cout << (double)num/(double)n <<"\n";
    }
    
    return 0;
}