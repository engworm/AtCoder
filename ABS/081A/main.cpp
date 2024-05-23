#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int a;
  std::cin >> a;

  int r = 0;
  for (int i = 0; i < 3; ++i) {
    if (a % 10 == 1) {
      r += 1;
    }
    a = a/10;
  }

  std::cout << r << std::endl;

  return 0;
}