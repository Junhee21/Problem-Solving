#include <iostream>
using namespace std;

int correctChess[6] = {1, 1, 2, 2, 2, 8};

int main(void) {
  int nowChess[6];
  for (int i = 0; i < 6; i++) {
    cin >> nowChess[i];
  }
  for (int i = 0; i < 6; i++) {
    cout << correctChess[i] - nowChess[i] << " ";
  }
  return 0;
}