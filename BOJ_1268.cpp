// 22 / 3 / 2

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> classes;
vector<int> scores;

int main(void)
{
  cin >> n;
  classes.assign(n, vector<int>(5, 0));
  scores.assign(n, 0);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 5; j++)
      cin >> classes[i][j];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < 5; k++)
      {
        if (classes[i][k] == classes[j][k])
        {
          scores[i]++;
          break;
        }
      }
    }
  }

  int maxStudent = 0, maxScore = 0;
  for (int i = 0; i < n; i++)
  {
    if (scores[i] > maxScore)
    {
      maxScore = scores[i];
      maxStudent = i + 1;
    }
  }
  cout << maxStudent;
  return 0;
}