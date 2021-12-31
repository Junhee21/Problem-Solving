// 21 / 12 / 31

#include <iostream>
using namespace std;

int arr[26];

int main(void)
{
    char str[101];
    cin >> str;

    for (int i=0; i<101; i++)
    {
        if (!str[i])
            break;
        arr[str[i]-'a']++;
    }

    for (int i=0; i<26; i++)
        cout << arr[i] << " ";
    return 0;
}