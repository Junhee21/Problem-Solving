#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
  string name;
  int k;
  int y;
  int s;
};
vector<Student> students;

bool cmp(Student a, Student b) {
  if (a.k != b.k)
    return a.k > b.k;
  if (a.y != b.y)
    return a.y < b.y;
  if (a.s != b.s)
    return a.s > b.s;
  return a.name < b.name;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string name;
    int k, y, s;
    cin >> name >> k >> y >> s;
    Student student{name, k, y, s};
    students.push_back(student);
  }

  sort(students.begin(), students.end(), cmp);

  for (int i = 0; i < n; i++) {
    cout << students[i].name << "\n";
  }
  return 0;
}