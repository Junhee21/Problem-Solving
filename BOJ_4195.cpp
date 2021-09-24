//21 09 25

#include <iostream>
#include <map>
#include <string>
using namespace std;

int parent_node[200000];
int set_size[200000];
int iter = 0;

int Find_value(string n, map<string, int> &m)
{
    if (m.count(n))
        return m[n];

    m.insert({n, iter++});
    return iter - 1;
}

int Find_parent(int node)
{
    if (parent_node[node] == node)
        return node;
    parent_node[node] = Find_parent(parent_node[node]);
    return parent_node[node];
}

void Union_set(int p1, int p2)
{
    int size1 = set_size[p1];
    int size2 = set_size[p2];


    //집합 union하는 방향을 설정하지 않아도 된다.
    // if (size1 >= size2)
    // {
    //     parent_node[p2] = p1;
    //     set_size[p1] += set_size[p2];
    //     set_size[p2]=0;
    //     cout<<set_size[p1]<<"\n";
    // }
    // else
    // {
    //     parent_node[p1] = p2;
    //     set_size[p2] += set_size[p1];
    //     set_size[p1]=0;
    //     cout<<set_size[p2]<<"\n";
    // }
    parent_node[p2] = p1;
    set_size[p1] += set_size[p2];
    set_size[p2]=0;
    cout<<set_size[p1]<<"\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin>>test_num;
    while (test_num--)
    {
        int n;
        cin>>n;
        for (int i=0; i<2*n; i++)
        {
            parent_node[i] = i;
            set_size[i] = 1;
        }

        map<string, int> name;
        iter = 0;
        while (n--)
        {
            string name1, name2;
            cin>>name1>>name2;

            int value1 = Find_value(name1, name);
            int value2 = Find_value(name2, name);

            int parent1 = Find_parent(value1);
            int parent2 = Find_parent(value2);

            if (parent1 == parent2)
                cout<<set_size[parent1]<<"\n";
            else
                Union_set(parent1, parent2);
        }
    }
    return 0;
}