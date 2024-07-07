#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>
#include <deque>
#include <stack>
#include <set>
#include <bitset>

bool intersection(int x1, int x2, int x3, int x4) {

  bool result = false;

  if (x1 > x2) {
    std::swap(x1, x2);
  }

  if (x3 > x4) {
    std::swap(x3, x4);
  }

  if ((x3 < x2 && x1 < x4) || (x1 < x4 && x3 < x2)) {
    result = true;
  }

  return result;

}

int main() {
  int a, b, c, d, e, f;
  std::cin >> a >> b >> c >> d >> e >> f;

  int g, h, i, j, k, l;
  std::cin >> g >> h >> i >> j >> k >> l;

  bool intersection_x = intersection(a, d, g, j);
  bool intersection_y = intersection(b, e, h, k);
  bool intersection_z = intersection(c, f, i, l);

  if (intersection_x && intersection_y && intersection_z) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}