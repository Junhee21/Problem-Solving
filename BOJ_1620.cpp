// 21/10/19

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<string> index_pokemon;
map<string, int> pokemon;

void Input(void)
{
    index_pokemon.push_back("non");
    for (int i=1; i<=n; i++)
    {
        string monster;
        cin>>monster;
        pokemon.insert({monster, i});
        index_pokemon.push_back(monster);
    }
}

void Output(void)
{
    while (m--)
    {
        string order;
        cin >> order;
        if (order[0]>48 && order[0]<58)
        {
            int x = 0;
            for (auto iter=order.begin(); iter!=order.end(); iter++)
            {
                x += (*iter - '0');
                x *= 10;
            }
            x /= 10;

            cout << index_pokemon[x]<<"\n";
        }
        else
            cout << pokemon[order]<<"\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    Input();
    Output();

    return 0;
}