//21 09 08

#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

vector<pair<int, int>> lis;
vector<int> back_tracking;
vector<int> answer;
int n;
int arr[1000000];

int Binary_search(int num)
{
    int front = 0;
    int back = lis.size()-1;
    int middle;
    while (back>front+1)
    {
        middle = (front+back)/2;
        if (lis[middle].first > num)
            back = middle;
        else
            front = middle;
    }
    if (lis[front].first >= num)
        return front;
    else
        return back;
}

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
            int index = Binary_search(arr[i]);
            if (index==0)
                back_tracking[i] = -1;
            else
                back_tracking[i] = lis[index-1].second;
            lis[index].first = arr[i];
            lis[index].second = i;
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
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    Search_lis();
    Do_back_tracking(lis.back().second);

    printf("%d\n", answer.size());
    for (int i=answer.size()-1; i>=0; i--)
        printf("%d ", answer[i]);
    return 0;
}