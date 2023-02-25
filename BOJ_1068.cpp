#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int parent;
  vector<int> child;
};

vector<Node *> tree;

int dfs(int curIndex) {
  if (tree[curIndex]->child.size() == 0)
    return 1;

  int num = 0;
  for (auto a : tree[curIndex]->child) {
    num += dfs(a);
  }
  return num;
}

int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    tree.push_back(new Node());
  }
  int rootNode;
  for (int i = 0; i < n; i++) {
    int parentNode;
    cin >> parentNode;
    tree[i]->parent = parentNode;
    if (parentNode == -1) {
      rootNode = i;
      continue;
    }
    tree[parentNode]->child.push_back(i);
  }

  int deletedTreeIndex;
  cin >> deletedTreeIndex;

  if (deletedTreeIndex == rootNode) {
    cout << 0;
    return 0;
  }

  vector<int> temp;

  for (auto a : tree[tree[deletedTreeIndex]->parent]->child) {
    if (a != deletedTreeIndex)
      temp.push_back(a);
  }
  tree[tree[deletedTreeIndex]->parent]->child = temp;

  cout << dfs(rootNode);
  return 0;
}