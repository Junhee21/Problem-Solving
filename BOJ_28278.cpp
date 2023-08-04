#include <iostream>
#include <vector>
using namespace std;

struct Node {
  Node *front = nullptr;
  int num;

  Node(Node *front, int num) {
    this->front = front;
    this->num = num;
  }
};

struct Stack {
  int size = 0;
  Node *top = nullptr;
};

void check_empty(Stack &stack) {
  if (stack.size == 0)
    cout << 1 << "\n";
  else
    cout << 0 << "\n";
}

void push(Stack &stack, int num) {
  stack.top = new Node(stack.top, num);
  stack.size++;
}

void pop(Stack &stack) {
  if (stack.top == nullptr) {
    cout << -1 << "\n";
  } else {
    cout << stack.top->num << "\n";
    stack.top = stack.top->front;
    stack.size--;
  }
}

void print_top(Stack &stack) {
  if (stack.top == nullptr) {
    cout << -1 << "\n";
  } else {
    cout << stack.top->num << "\n";
  }
}

void print_size(Stack &stack) { cout << stack.size << "\n"; }

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  Stack stack;

  while (n--) {
    int a;
    cin >> a;
    if (a == 1) {
      int b;
      cin >> b;
      push(stack, b);
    } else if (a == 2) {
      pop(stack);
    } else if (a == 3) {
      print_size(stack);
    } else if (a == 4) {
      check_empty(stack);
    } else {
      print_top(stack);
    }
  }
  return 0;
}