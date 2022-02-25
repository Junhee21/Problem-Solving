// 22 / 1 / 22

#include <iostream>
#include <cmath>
using namespace std;
double x_1, y_1, r_1, x_2, y_2, r_2;

double solve(void)
{
  double len = sqrt(pow(x_2 - x_1, 2) + pow(y_2 - y_1, 2));
  if (len >= r_1 + r_2)
    return 0;

  if (abs(r_1 - r_2) >= len)
    return min(pow(r_1, 2), pow(r_2, 2)) * M_PI;

  double bottom1 = (pow(r_1, 2) - pow(r_2, 2) + pow(len, 2)) / (2 * len);
  double bottom2 = (pow(r_2, 2) - pow(r_1, 2) + pow(len, 2)) / (2 * len);
  double height = sqrt(pow(r_1, 2) - pow(bottom1, 2));

  double totalArea = 0;
  totalArea += (pow(r_1, 2) * acos(bottom1 / r_1) - height * bottom1);
  totalArea += (pow(r_2, 2) * acos(bottom2 / r_2) - height * bottom2);
  return totalArea;
}

int main(void)
{
  cout << fixed;
  cout.precision(3);
  cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
  cout << solve();
  return 0;
}