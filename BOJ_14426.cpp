#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie {
  vector<Trie *> children;
  Trie() { this->children.assign(26, nullptr); }
  void insert(string &str, int idx) {
    if (idx == str.size()) {
      return;
    }
    if (this->children[str[idx] - 'a'] == nullptr) {
      this->children[str[idx] - 'a'] = new Trie();
    }
    this->children[str[idx] - 'a']->insert(str, idx + 1);
  }
  bool search(string &str, int idx) {
    if (idx == str.size())
      return true;
    if (this->children[str[idx] - 'a'] == nullptr)
      return false;
    return this->children[str[idx] - 'a']->search(str, idx + 1);
  }
};

void insert(string &str) {}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  Trie trie;

  while (n--) {
    string str;
    cin >> str;
    trie.insert(str, 0);
  }

  int res = 0;
  while (m--) {
    string str;
    cin >> str;
    if (trie.search(str, 0))
      res++;
  }
  cout << res;
  return 0;
}