#include <iostream>
using namespace std;

class Node {
private:
  bool finish = false;
  Node *children[10];

public:
  void insert(string &str, int index) {
    if (index == str.size()) {
      finish = true;
      return;
    }
    int num = str[index] - '0';
    if (!children[num]) {
      children[num] = new Node();
    }
    children[num]->insert(str, index + 1);
  }
  bool check() {
    for (int i = 0; i < 10; i++) {
      if (this->children[i] && this->finish) {
        return false;
      }
    }
    for (int i = 0; i < 10; i++) {
      if (this->children[i]) {
        if (!this->children[i]->check()) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(void) {
  int N;
  cin >> N;

  while (N--) {
    int n;
    cin >> n;
    Node *root = new Node();
    while (n--) {
      string s;
      cin >> s;
      root->insert(s, 0);
    }
    if (root->check()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}