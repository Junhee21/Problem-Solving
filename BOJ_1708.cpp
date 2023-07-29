#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Point {
  long long x, y;
};

vector<Point> points;

long long get_ccw(Point a, Point b, Point s) {
  return (a.x - s.x) * (b.y - s.y) - (a.y - s.y) * (b.x - s.x);
}

bool compare(Point a, Point b) { return a.y == b.y ? a.x < b.x : a.y < b.y; }

bool compare_by_angle(Point a, Point b) {
  long long ccw = get_ccw(a, b, points[0]);
  return ccw == 0 ? a.y == b.y ? a.x < b.x : a.y < b.y : ccw > 0;
}

int main(void) {
  int n;
  cin >> n;

  points.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }

  sort(points.begin(), points.end(), compare);
  sort(points.begin() + 1, points.end(), compare_by_angle);

  stack<Point> convex_hull;

  convex_hull.push(points[0]);
  convex_hull.push(points[1]);

  for (int i = 2; i < n; i++) {
    while (convex_hull.size() >= 2) {
      Point b = convex_hull.top();
      convex_hull.pop();
      Point a = convex_hull.top();

      if (get_ccw(points[i], a, b) > 0) {
        convex_hull.push(b);
        break;
      }
    }
    convex_hull.push(points[i]);
  }
  cout << convex_hull.size();
  return 0;
}