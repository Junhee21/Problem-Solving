//21 09 19

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000+1;

int inorder[MAX];
int postorder[MAX];
int n;

void Find_preorder(int inf, int inl, int pof, int pol)
{
    int node = postorder[pol];
    if (inf>inl)
        return;
    cout<<node<<" ";
    if (inf==inl)
        return;
    
    int inlf, inll, inrf, inrl, polf, poll, porf, porl;
    for (int i=0; 1; i++)
    {
        if (inorder[i+inf] == node)
        {
            inlf = inf, inll = inf+i-1, inrf = inf+i+1, inrl = inl;
            polf = pof, poll = pof+i-1, porf = pof+i, porl = pol - 1;
            break;
        }
    }

    Find_preorder(inlf, inll, polf, poll);
    Find_preorder(inrf, inrl, porf, porl);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for (int i=0; i<n; i++)
        cin>>inorder[i];
    for (int i=0; i<n; i++)
        cin>>postorder[i];

    Find_preorder(0, n-1, 0 ,n-1);
    return 0;
}