// 21/10/23

#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> s;
set<string> answer;

void never_hear(int i)
{
    while (i--)
    {
        string person;
        cin >> person;
        s.insert(person);
    }
}

int nerver_look(int i)
{
    int total_person = 0;
    while (i--)
    {
        string person;
        cin >> person;
        if (s.count(person))
        {
            total_person++;
            answer.insert(person);
        }
    }
    return total_person;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    never_hear(n);
    cout << nerver_look(m);
    for (auto i = answer.begin(); i!=answer.end(); i++)
        cout <<"\n"<< *i;
    return 0;
}