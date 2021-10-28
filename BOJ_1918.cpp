// 21/10/28

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    string operation = "()+-*/";
    string answer;
    stack<pair<int, int>> oper;
    int num = 0;
    for (auto iter=s.begin(); iter!=s.end(); iter++)
    {
        if ((*iter)-'A' >= 0)
            answer += (*iter);
        else
        {
            int index = 0;
            for (int i=0; i<6; i++)
            {
                if ((*iter) == operation[i])
                {
                    index = i;
                    break;
                }
            }
            if (index == 0)
                num++;
            else if (index == 1)
                num--;
            else
            {
                while (!oper.empty())
                {
                    int before_num = oper.top().first;
                    int before_index = oper.top().second;
                    if (before_num<num || ((before_num==num)&&(before_index/2 < index/2)))
                        break;

                    answer.push_back(operation[before_index]);
                    oper.pop();        
                }
                oper.push({num, index});
            }
        }
    }
    while (!oper.empty())
    {
        answer += operation[oper.top().second];
        oper.pop();
    }
    cout << answer;
    return 0;
}