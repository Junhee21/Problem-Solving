// 21 / 12 / 16

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> leftStack;
stack<char> rightStack;
string str;

void moveLeft(void)
{
    if (!leftStack.empty())
    {
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
}

void moveRight(void)
{
    if (!rightStack.empty())
    {
        leftStack.push(rightStack.top());
        rightStack.pop();
    }
}

void popChar(void)
{
    if (!leftStack.empty())
        leftStack.pop();
}

void pushChar(void)
{
    char x;
    cin >> x;
    leftStack.push(x);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for (int i = 0; i < (int)str.size(); i++)
        leftStack.push(str[i]);

    int t;
    cin >> t;

    while (t--)
    {
        char order;
        cin >> order;
        if (order == 'L')
            moveLeft();
        else if (order == 'D')
            moveRight();
        else if (order == 'B')
            popChar();
        else
            pushChar();
    }

    while (!leftStack.empty())
    {
        rightStack.push(leftStack.top());
        leftStack.pop();
    }

    while (!rightStack.empty())
    {
        cout << rightStack.top();
        rightStack.pop();
    }

    return 0;
}