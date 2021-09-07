//21 09 07

#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int>> lis;
vector<int> back_tracking;
vector<int> answer;
int n;
int arr[1000];

void Search_lis(void)
{
    back_tracking.assign(n, INF);
    for (int i=0; i<n; i++)
    {
        if (lis.empty())
        {
            lis.push_back({arr[i], i});
            back_tracking[i] = -1;
        }
        else if (lis.back().first < arr[i])
        {
            back_tracking[i] = lis.back().second;
            lis.push_back({arr[i], i});
        }
        else
        {
            for (int j=0; j<lis.size(); j++)
            {
                if (arr[i]<=lis[j].first)
                {
                    if (j==0)
                        back_tracking[i] = -1;
                    else
                        back_tracking[i] = lis[j-1].second;
                    lis[j].first = arr[i];
                    lis[j].second = i;
                    break;
                }
            }
        }
    }
}

void Do_back_tracking(int index)
{
    answer.push_back(arr[index]);
    int next_index = back_tracking[index];
    if (next_index!=-1)
        Do_back_tracking(next_index);
}

int main(void)
{
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>arr[i];

    Search_lis();
    Do_back_tracking(lis.back().second);

    cout<<lis.size()<<endl;
    for (int i=answer.size()-1; i>=0; i--)
        cout<<answer[i]<<" ";
    return 0;
}