// 21/10/22

#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

int main(void)
{
    cin >> n >> m >> s;

    bool check = false;
    int answer = 0;
    int index = 0;
    for (int i=0; i<(int)s.size(); i++)
    {
        if (index == 0)
        {
            if (s[i] == 'I')
                index++;
        }
        else if (!check)
        {
            if (index%2 == 1)
            {
                if (s[i] == 'O')
                    index++;
                else
                    index = 1;
            }
            else
            {
                if (s[i] == 'I')
                {
                    index ++;
                    if (index == 2*n+1)
                    {
                        check = true;
                        answer ++;
                    }
                }
                else
                    index = 0;
            }
        }
        else
        {
            if (index%2 == 1)
            {
                if (s[i] == 'O')
                    index++;
                else
                {
                    check = false;
                    index = 1;
                }
            }
            else
            {
                if (s[i] == 'I')
                {
                    answer++;
                    index++;
                }
                else
                {
                    check = false;
                    index = 0;
                }
            }
        }
    }

    cout << answer;
    return 0;
}