// 21/11/06

#include <iostream>
#include <map>
#include <string>
using namespace std;

string I = "I";

struct double_pri_q
{
    map<int, int> bucket;
    map<int, int>::iterator iter;
    int size_bucket = 0;

    void insert(int num)
    {
        if (!bucket.count(num))
        {
            bucket.insert({num, 1});
            size_bucket ++;
        }
        else
            bucket[num] ++;
    }

    void pop(int dir)
    {
        if (size_bucket==0)
            return;

        if (dir == 1)
        {
            iter = --bucket.end();
            if (iter->second == 1)
            {
                bucket.erase(iter);
                size_bucket--;
            }
            else
            {
                iter->second--;
            }
        }
        if (dir == -1)
        {
            iter = bucket.begin();
            if (iter->second == 1)
            {
                bucket.erase(iter);
                size_bucket--;
            }
            else
            {
                iter->second--;
            }
        }
    }

    void output(void)
    {
        if (size_bucket == 0)
            cout << "EMPTY";
        else
            cout << (--bucket.end())->first <<" " << bucket.begin()->first;
        cout << "\n";
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        struct double_pri_q dpq;
        int n;
        cin >> n;
        while (n--)
        {
            string str;
            int x;
            cin >> str >> x;
            if (str == I)
                dpq.insert(x);
            else
                dpq.pop(x);
        }

        dpq.output();
    }
    return 0;
}