#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int a, b;
  std::cin >> a >> b;

  int c = a*b;
  if (c%2 == 0) {
    std::cout << "Even" << std::endl;
  }
  else {
    std::cout << "Odd" << std::endl;
  }

  return 0;
}