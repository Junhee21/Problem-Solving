// 22 / 1 / 20

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

double x, y, d, t;

double solve(void)
{
    double length = sqrt(x * x + y * y);
    if (d < t)
        return length;

    double num = 0;
    while (length >= d)
    {
        length -= d;
        num += t;
    }
    if (num > 0)
        return num + min(length, t);
    else
    {
        vector<double> arr = {length, t + d - length, 2 * t};
        return num + *min_element(arr.begin(), arr.end());
    }
}

int main(void)
{
    cout << fixed;
    cout.precision(10);
    cin >> x >> y >> d >> t;

    double time = 0;
    cout << solve();
    return 0;
}