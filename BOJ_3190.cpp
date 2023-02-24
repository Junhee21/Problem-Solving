#include <iostream>
#include <vector>
using namespace std;

struct Node {
  Node(int r, int c, int dir) {
    this->r = r;
    this->c = c;
    this->dir = dir;
  }
  int r = 0, c = 0, dir = 0;
  // 0, 1, 2, 3 위 오른쪽 아래 왼쪽
  Node *nextNode;
};

class Snake {
public:
  Snake() {
    head = new Node(1, 1, 1);
    tail = head;
    tail->nextNode = head;
  }
  bool move(vector<vector<int>> &board, int turnDir) {
    int r = head->r, c = head->c;
    if (head->dir == 0) {
      r--;
    } else if (head->dir == 1) {
      c++;
    } else if (head->dir == 2) {
      r++;
    } else {
      c--;
    }

    if (r >= board.size() || r <= 0 || c >= board[1].size() || c <= 0 ||
        board[r][c] == 1)
      return false;
    int newDir = head->dir;
    if (turnDir == -1) {
      newDir--;
      if (newDir == -1)
        newDir = 3;
    } else if (turnDir == 1) {
      newDir++;
      if (newDir == 4)
        newDir = 0;
    }
    Node *newHead = new Node(r, c, newDir);
    head->nextNode = newHead;
    head = newHead;
    if (board[r][c] == 0) {
      board[tail->r][tail->c] = 0;
      Node *temp = tail->nextNode;
      delete tail;
      tail = temp;
    }

    board[r][c] = 1;

    return true;
  };

private:
  Node *head;
  Node *tail;
};

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
  vector<pair<int, char>> commands;
  Snake *snake = new Snake();
  board[1][1] = 1;
  int appleNum;
  cin >> appleNum;
  for (int i = 0; i < appleNum; i++) {
    int a, b;
    cin >> a >> b;
    board[a][b] = 2;
  }
  int moveNum;
  cin >> moveNum;
  int cnt = 0;
  for (int i = 0; i < moveNum; i++) {
    int endTime;
    char c;
    cin >> endTime >> c;
    commands.push_back({endTime, c});
  }
  int commandsIndex = 0;
  while (true) {
    int newDir = 0;
    if (commandsIndex < moveNum && cnt == commands[commandsIndex].first - 1) {
      if (commands[commandsIndex++].second == 'D')
        newDir = 1;
      else
        newDir = -1;
    }

    if (!snake->move(board, newDir)) {
      cout << cnt + 1;
      return 0;
    }
    cnt++;
  }
}