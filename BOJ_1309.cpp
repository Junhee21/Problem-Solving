#include <iostream>
using namespace std;

const int quotient = 9901;

int main(void) {
  int n;
  cin >> n;
  int emptyCnt = 1;
  int leftCnt = 0;
  int rightCnt = 0;
  while (n--) {
    int tempEmptyCnt = leftCnt + rightCnt + emptyCnt;
    int tempLeftCnt = rightCnt + emptyCnt;
    int tempRightCnt = leftCnt + emptyCnt;
    emptyCnt = tempEmptyCnt % quotient;
    rightCnt = tempRightCnt % quotient;
    leftCnt = tempLeftCnt % quotient;
  }
  cout << (emptyCnt + leftCnt + rightCnt) % quotient;
  return 0;
}