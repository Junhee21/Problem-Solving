// 21 / 12 / 27

#include <iostream>
using namespace std;

int main(void)
{
    int hamburger[3];
    for (int i = 0; i < 3; i++)
        cin >> hamburger[i];
    int minHamburger = 987654321;
    for (int i = 0; i < 3; i++)
    {
        if (hamburger[i] < minHamburger)
            minHamburger = hamburger[i];
    }
    int drink[3];
    for (int i = 0; i < 2; i++)
        cin >> drink[i];
    int minDrink = 987654321;
    for (int i = 0; i < 2; i++)
    {
        if (drink[i] < minDrink)
            minDrink = drink[i];
    }
    cout << minHamburger + minDrink - 50;
    return 0;
}