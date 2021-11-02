// 21/11/02

#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> score[100000];

int Solve(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> score[i].first >>score[i].second;

    sort(score, score+n);

    int answer = 1;
    int high = score[0].second;
    for (int i=1; i<n; i++)
    {
        if (score[i].second < high)
        {
            answer ++;
            high = score[i].second;
        }
    }
    return answer;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cout << Solve() << "\n";
    }
    return 0;
}