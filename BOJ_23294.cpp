// 21/11/07

#include <iostream>
#include <deque>
#include <string>
using namespace std;

int cash[2001];
int n, m, c;

struct web_browser
{
    deque<int> backward;
    deque<int> frontward;
    int limit_cash;
    int now = -1;

    void go_backward()
    {
        if (backward.empty())
            return;
        frontward.push_front(now);
        now = backward.back();
        backward.pop_back();
    }

    void go_frontward()
    {
        if (frontward.empty())
            return;
        backward.push_back(now);
        now = frontward.front();
        frontward.pop_front();
    }

    void access(int num)
    {
        while (!frontward.empty())
        {
            int x = frontward.front();
            limit_cash += cash[x];
            frontward.pop_front();
        }
        if (now != -1)
            backward.push_back(now);

        now = num;
        limit_cash -= cash[num];

        while (limit_cash <0)
        {
            int x = backward.front();
            limit_cash += cash[x];
            backward.pop_front();
        }
    }

    void compress()
    {
        backward = compress_backward(backward);
    }

    deque<int> compress_backward(deque<int>backward)
    {
        deque<int> output;
        for (int i=0; i<(int)backward.size(); i++)
        {
            if (i == backward.size()-1)
                break;
            
            if (backward[i] != backward[i+1])
                output.push_back(backward[i]);
            else
                limit_cash += cash[backward[i]];
        }
        if (!backward.empty())
            output.push_back(backward.back());
        return output;
    }

    void output()
    {
        cout << now << "\n";
        if (backward.empty())
        {
            cout << -1;
        }
        else
        {
            for (auto iter = backward.rbegin(); iter!=backward.rend(); iter++)
                cout << *iter <<" ";
        }
        cout <<"\n";
        if (frontward.empty())
        {
            cout << -1;
        }
        else
        {
            for (auto iter = frontward.begin(); iter!=frontward.end(); iter++)
                cout << *iter <<" ";
        }
        cout << "\n";
    }
};

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;
    for (int i=1; i<=n; i++)
        cin >> cash[i];

    struct web_browser wb;
    wb.limit_cash = c;

    while (m--)
    {
        string order;
        cin >> order;

        if (order == (string)"B")
            wb.go_backward();
        else if (order == (string)"F")
            wb.go_frontward();
        else if (order == (string)"A")
        {
            int x;
            cin >> x;
            wb.access(x);
        }
        else
            wb.compress();

    }
    wb.output();

    return 0;
}