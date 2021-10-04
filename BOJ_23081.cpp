//21 10 03

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int matrix[500][500];
string wb = "WB";
vector<int> delta_i = {-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> delta_j = {0, 1, 1, 1, 0, -1, -1 ,-1};
vector<int> answer = {0, 0, 0};

void Othello(int i, int j)
{
    int total_num = 0;
    for (int k=0; k<8; k++)
    {
        for (int m=1; 1; m++)
        {
            int new_i = i + delta_i[k]*m;
            int new_j = j + delta_j[k]*m;
            if (new_i<0 || new_i==n || new_j<0 || new_j==n)
                break;
            if (matrix[new_i][new_j] == -1)
                break;
            if (matrix[new_i][new_j] == 0)
            {
                total_num += (m-1);
                break;
            }
        }
    }
    if (total_num > answer[0])
    {
        answer[0] = total_num;
        answer[1] = i;
        answer[2] = j;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for (int j=0; j<n; j++)
        {
            if (s[j] == wb[1])
                matrix[i][j] = 0;
            else if (s[j] == wb[0])
                matrix[i][j] = 1;
            else
                matrix[i][j] = -1;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (matrix[i][j] == -1)
                Othello(i, j);
        }
    }
    
    if (answer[0] == 0)
        cout<<"PASS";
    else
        cout<<answer[2]<<" "<<answer[1]<<"\n"<<answer[0];

    return 0;
}