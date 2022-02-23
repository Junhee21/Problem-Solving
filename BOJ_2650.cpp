// 22 / 2 / 23

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> intersection;

void input(void)
{
  for (int i = 0; i < n; i++)
  {
    int dir, val;
    cin >> dir >> val;
    if (dir == 1)
    {
      arr.push_back({val, i / 2});
    }
    else if (dir == 2)
    {
      arr.push_back({150 - val, i / 2});
    }
    else if (dir == 3)
    {
      arr.push_back({200 - val, i / 2});
    }
    else
    {
      arr.push_back({50 + val, i / 2});
    }
  }
  sort(arr.begin(), arr.end());
}

void search(void)
{
  intersection.assign(n / 2, -1);
  for (int i = 0; i < n; i++)
  {
    int num = arr[i].second;
    if (intersection[num] != -1)
      continue;

    vector<bool> check(n / 2, true);
    int nowInter = 0;

    for (int j = i + 1; j < n; j++)
    {
      int targetNum = arr[j].second;
      if (num == targetNum)
      {
        intersection[num] = nowInter;
        break;
      }

      if (check[targetNum])
      {
        nowInter++;
        check[targetNum] = false;
      }
      else
        nowInter--;
    }
  }

  int totalNum = 0;
  int maxNum = 0;
  for (int i = 0; i < n / 2; i++)
  {
    maxNum = intersection[i] > maxNum ? intersection[i] : maxNum;
    totalNum += intersection[i];
  }
  cout << totalNum / 2 << "\n"
       << maxNum;
}

int main(void)
{
  cin >> n;
  input();
  search();
  return 0;
}