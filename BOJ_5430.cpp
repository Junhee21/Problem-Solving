// 21/10/19

#include <iostream>
#include <string>
using namespace std;

string order;
string input_arr;
int n, front, back;
int arr[100000];

void Input(void)
{
    cin >> order >> n >> input_arr;
    int i = 0;
    int temp = 0;
    for (auto iter=input_arr.begin(); iter!=input_arr.end(); iter++)
    {
        if (*iter == '[')
            continue;
        if ((*iter == ',')||(*iter == ']'))
        {
            arr[i++] = temp;
            temp = 0;
        }
        else
        {
            temp*=10;
            temp += (*iter - '0');
        }
    }
}

void Solve(void)
{
    front = 0; back = n-1;
    bool check = true;
    for (auto iter=order.begin(); iter!=order.end(); iter++)
    {
        if (*iter == 'R')
            check = !check;
        else
        {
            if (check)
                front++;
            else
                back--;
        }
    }

    if (front > back+1)
        cout<<"error\n";
    else if (front == back+1)
        cout<<"[]\n";
    else
    {
        cout<<"[";
        if (check)
        {
            for (int i = front; i<back; i++)
                cout<<arr[i]<<",";
            cout<<arr[back];
        }
        else
        {
            for (int i = back; i>front; i--)
                cout<<arr[i]<<",";
            cout<<arr[front];
        }
        cout <<"]\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num;
    while (test_num --)
    {
        Input();
        Solve();
    }

    return 0;
}