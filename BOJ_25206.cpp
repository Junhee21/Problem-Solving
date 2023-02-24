#include <iostream>
#include <map>
#include <string>
using namespace std;
string PASS = "P";

int main(void) {
  map<string, double> gradeTable;
  gradeTable.insert({"A+", 4.5});
  gradeTable.insert({"A0", 4.0});
  gradeTable.insert({"B+", 3.5});
  gradeTable.insert({"B0", 3.0});
  gradeTable.insert({"C+", 2.5});
  gradeTable.insert({"C0", 2.0});
  gradeTable.insert({"D+", 1.5});
  gradeTable.insert({"D0", 1.0});
  gradeTable.insert({"F", 0.0});

  double maxNum = 0.0;
  double maxGrade = 0.0;

  for (int i = 0; i < 20; i++) {
    string name;
    double num;
    string grade;
    cin >> name >> num >> grade;
    if (grade.compare(PASS) == 0) {
      continue;
    }
    maxNum += num;
    maxGrade += num * gradeTable[grade];
  }

  cout << maxGrade / maxNum;
  return 0;
}