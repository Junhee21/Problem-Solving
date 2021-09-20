//21 09 19

#include <iostream>
using namespace std;

// 완전 이진 트리를 일차원 배열로 구성
// 기억 공간의 낭비가 심하다
// -> node가 n개 일 때, 최악의 경우 2^n 크기 배열이 필요하므로 포화이진트리가 아니라면 메모리낭비가 심하다.
// -> 이 문제는 vector 로 구현하자


// int tree[1000000];

// void Search_postorder(int node)
// {
//     if (!tree[node])
//         return;
//     Search_postorder(node*2);
//     Search_postorder(node*2+1);
//     cout<<tree[node]<<'\n';
// }

// int main(void)
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     for (int i=0; i<=10000; i++)
//         tree[i] = 0;
    
//     int index = 1;
//     int x;
//     cin>>x;
//     tree[index] = x;
//     tree[0] = 987654321;

//     while (1)
//     {
//         cin>>x;
//         if (cin.eof())
//             break;
        
//         if (x<tree[index])
//             index *= 2;
//         else
//         {
//             while (1)
//             {
//                 if (tree[index/2] > x)
//                 {
//                     index = index*2+1;
//                     break;
//                 }
//                 else
//                     index /= 2;
//             }
//         }
//         tree[index] = x;
//     }

//     Search_postorder(1);

//     return 0;
// }
int tree[100000];

void Search_postorder(int first, int last)
{
    if (first >= last)
        return;
    
    int node = tree[first];
    int index = first;
    while (1)
    {
        if (index>=last || tree[index]>node)
            break;
        index++;
    }
    Search_postorder(first+1, index);
    Search_postorder(index, last);
    cout<<node<<"\n";
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i;
    for (i=0; 1; i++)
    {
        int x;
        cin>>x;
        if (cin.eof())
            break;
        tree[i] = x;
    }

    Search_postorder(0, i);

    return 0;
}