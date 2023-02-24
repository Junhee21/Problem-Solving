#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  while (true) {
    int num;
    cin >> num;
    if (num == -1)
      return 0;
    int sum = 0;
    vector<int> arr;
    for (int i = 1; i * i <= num; i++) {
      if (num % i != 0)
        continue;
      if (i * i == num) {
        sum += i;
        arr.push_back(i);
      } else {
        sum += (i + num / i);
        arr.push_back(i);
      }
    }
    sum -= num;
    if (sum != num) {
      cout << num << " is NOT perfect.\n";
    } else {
      cout << num << " = ";
      for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " + ";
      }
      for (int i = arr.size() - 1; i >= 1; i--) {
        if (arr[i] * arr[i] == num)
          continue;
        cout << num / arr[i];
        if (i == 1)
          cout << "\n";
        else
          cout << " + ";
      }
    }
  }
  return 0;
}