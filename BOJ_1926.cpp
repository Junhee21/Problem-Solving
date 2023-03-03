#include <iostream>
#include <vector>
using namespace std;

int row, col;
int numPaint = 0, maxPaint = 0;
vector<vector<int>> paint;
vector<vector<bool>> checked;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int search(int r, int c) {
  if (checked[r][c])
    return 0;
  checked[r][c] = true;
  if (paint[r][c] == 0)
    return 0;
  int sum = 1;
  for (int i = 0; i < 4; i++) {
    int newR = r + dir[i].first;
    int newC = c + dir[i].second;
    if (newR == -1 || newR == row || newC == -1 || newC == col)
      continue;
    sum += search(newR, newC);
  }
  return sum;
}

int main(void) {
  cin >> row >> col;
  paint.assign(row, vector<int>(col, 0));
  checked.assign(row, vector<bool>(col, false));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cin >> paint[i][j];
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      int sum = search(i, j);
      numPaint = sum > 0 ? numPaint + 1 : numPaint;
      maxPaint = sum > maxPaint ? sum : maxPaint;
    }
  }
  cout << numPaint << "\n" << maxPaint;
  return 0;
}