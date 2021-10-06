//21 10 06

#include <iostream>

void Solve (int*arr)
{
    if (arr[0] == 1)
    {
        for (int i=1; i<8; i++)
        {
            if (arr[i] != (i+1))
            {
                std::cout << "mixed";
                return;
            }
        }
        std::cout << "ascending";
        return;
    }
    if (arr[0] == 8)
    {
        for (int i=1; i<8; i++)
        {
            if (arr[i] != (8-i))
            {
                std::cout << "mixed";
                return;
            }
        }
        std::cout << "descending";
        return;
    }
    std::cout << "mixed";
}

int main(void)
{
    int arr[8];
    for (int i=0; i<8; i++)
        std::cin>>arr[i];

    Solve(arr);
    return 0;
}