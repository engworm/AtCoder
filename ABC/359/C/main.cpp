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

int main() {
  long long sx, sy, tx, ty;
  std::cin >> sx >> sy >> tx >> ty;

  long long h = std::abs(ty - sy);
  long long w = std::abs(tx - sx);

  long long result = 0;
  if (w <= h) {
    result = h;
  }
  else {
    // [x1, x2] 内に含まれる偶数または奇数の数を求める
    long long w2 = [&ty] (long long x1, long long x2) -> long long {
      if (x1 > x2) {
        std::swap(x1, x2);
      }

      long long c = (x2 - x1)/2;
      return c;

    }(sx+h+0.5, tx+0.5);

    result = h + w2; 
  }

  std::cout << result << std::endl;

  return 0;
}