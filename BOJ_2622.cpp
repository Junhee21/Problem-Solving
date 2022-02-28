// 22 / 2 / 28

#include <iostream>
using namespace std;

int main(void)
{
  int num = 0, answer = 0;
  cin >> num;
  for (int i = 1; i <= num; i++)
  {
    for (int j = i; j <= num; j++)
    {
      int k = num - i - j;
      if (k < j)
        break;
      if (k < i + j)
        answer++;
    }
  }
  cout << answer;
  return 0;
}