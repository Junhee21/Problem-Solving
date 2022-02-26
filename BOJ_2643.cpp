// 22 / 2 / 26

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> paper;
vector<int> lis;

void searchLis(void)
{
  lis.push_back(paper[0].second);
  for (int i = 1; i < n; i++)
  {
    if (paper[i].second >= lis.back())
      lis.push_back(paper[i].second);
    else
    {
      for (int j = 0; j < (int)lis.size(); j++)
      {
        if (paper[i].second < lis[j])
        {
          lis[j] = paper[i].second;
          break;
        }
      }
    }
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  paper.assign(n, {0, 0});
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    if (x > y)
      swap(x, y);
    paper[i] = {x, y};
  }

  sort(paper.begin(), paper.end());

  searchLis();
  cout << lis.size();
  return 0;
}