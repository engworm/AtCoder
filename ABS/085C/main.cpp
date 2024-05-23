#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int N, Y;
  std::cin >> N >> Y;

  bool find_Y = false;
  for (int x = 0; x <= N; ++x) {
    if (find_Y) break;

    for (int y = 0; y <= N-x; ++y) {
      int z = N-x-y;
      int s = 10000*x + 5000*y + 1000*z;
      if (s == Y) {
        std::cout << x << ' ' << y << ' ' << z << std::endl;
        find_Y = true;
        break;
      }
    }
  }

  if (!find_Y) std::cout << -1 << ' ' << -1 << ' ' << -1 << std::endl;


  return 0;
}