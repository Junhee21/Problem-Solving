// 21/11/02

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> weight(n,0);
    for (int i=0; i<n; i++)
        cin >> weight[i];
    
    sort(weight.begin(), weight.end());
    
    for (int i=0; i<n; i++)
        weight[i] *= (n-i);

    cout << *max_element(weight.begin(), weight.end());
    return 0;
}