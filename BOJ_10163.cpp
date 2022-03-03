// 22 / 3 / 3

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix(1001, vector<int>(1001, -1));
int n;

int main(void)
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j < a + c; j++)
    {
      for (int k = b; k < b + d; k++)
        matrix[j][k] = i;
    }
  }
  for (int i = 0; i < n; i++)
  {
    int score = 0;
    for (int j = 0; j < 1001; j++)
    {
      for (int k = 0; k < 1001; k++)
      {
        if (matrix[j][k] == i)
          score++;
      }
    }
    cout << score << "\n";
  }
  return 0;
}