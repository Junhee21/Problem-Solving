// 21 09 19

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 27;

vector<pair<int, bool>> tree[MAX];
int n;

void Preorder(int node)
{
    cout << static_cast<char>(node + 'A');
    for (int i = 0; i < tree[node].size(); i++)
        Preorder(tree[node][i].first);
}

void Inorder(int node)
{
    if (tree[node].size() && tree[node][0].second)
        Inorder(tree[node][0].first);

    cout << static_cast<char>(node + 'A');

    for (int i = 0; i < tree[node].size(); i++)
    {
        if (!tree[node][i].second)
            Inorder(tree[node][i].first);
    }
}

void Postorder(int node)
{
    for (int i = 0; i < tree[node].size(); i++)
        Postorder(tree[node][i].first);

    cout << static_cast<char>(node + 'A');
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        if (b != '.')
            tree[a - 'A'].push_back({b - 'A', true});
        if (c != '.')
            tree[a - 'A'].push_back({c - 'A', false});
    }

    Preorder(0);
    cout << '\n';
    Inorder(0);
    cout << '\n';
    Postorder(0);

    return 0;
}