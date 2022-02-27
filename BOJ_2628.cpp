// 22 / 2 / 27

#include <iostream>
#include <vector>
using namespace std;

int widthNum, heightNum;
vector<bool> widthCheck;
vector<bool> heightCheck;

int main(void)
{
  cin >> widthNum >> heightNum;
  widthCheck.assign(widthNum + 1, false);
  heightCheck.assign(heightNum + 1, false);

  int lineNum;
  cin >> lineNum;
  while (lineNum--)
  {
    int dir, num;
    cin >> dir >> num;
    if (dir == 0)
      heightCheck[num] = true;
    else
      widthCheck[num] = true;
  }

  heightCheck[heightNum] = true;
  widthCheck[widthNum] = true;
  int maxArea = 0;
  int widthStart = 0;
  int heightStart = 0;
  for (int i = 0; i <= widthNum; i++)
  {
    heightStart = 0;
    if (widthCheck[i])
    {
      for (int j = 0; j <= heightNum; j++)
      {
        if (heightCheck[j])
        {
          if ((i - widthStart) * (j - heightStart) > maxArea)
            maxArea = (i - widthStart) * (j - heightStart);
          heightStart = j;
        }
      }
      widthStart = i;
    }
  }

  cout << maxArea;
  return 0;
}