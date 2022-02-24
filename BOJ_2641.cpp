// 22 / 2 / 24

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
vector<int> target;
vector<int> targetReverse;
vector<vector<int>> answer;
vector<int> caseArr;
bool check = false;

void dfs(int node, int level)
{
  if (level == len)
  {
    check = true;
    return;
  }

  if (target[level] == caseArr[node])
  {
    if (node + 1 == len)
      dfs(0, level + 1);
    else
      dfs(node + 1, level + 1);
  }
}

void dfsReverse(int node, int level)
{
  if (level == len)
  {
    check = true;
    return;
  }

  if (targetReverse[level] == caseArr[node])
  {
    if (node + 1 == len)
      dfsReverse(0, level + 1);
    else
      dfsReverse(node + 1, level + 1);
  }
}

int main(void)
{
  cin >> len;
  target.assign(len, 0);
  for (int i = 0; i < len; i++)
    cin >> target[i];
  for (int i = len - 1; i >= 0; i--)
  {
    if (target[i] % 2 == 1)
    {
      targetReverse.push_back(4 - target[i]);
    }
    else
    {
      targetReverse.push_back(6 - target[i]);
    }
  }

  int testCase;
  cin >> testCase;
  while (testCase--)
  {
    check = false;
    caseArr.assign(len, 0);
    for (int i = 0; i < len; i++)
      cin >> caseArr[i];

    for (int i = 0; i < len; i++)
    {
      if (check)
        break;
      dfs(i, 0);
    }
    for (int i = 0; i < len; i++)
    {
      if (check)
        break;
      dfsReverse(i, 0);
    }

    if (check)
      answer.push_back(caseArr);
  }

  cout << answer.size() << "\n";
  for (int i = 0; i < answer.size(); i++)
  {
    for (int j = 0; j < len; j++)
      cout << answer[i][j] << " ";
    cout << '\n';
  }
  return 0;
}