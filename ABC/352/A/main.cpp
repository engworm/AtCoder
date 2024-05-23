#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int N, X, Y, Z;
  std::cin >> N >> X >> Y >> Z;

  bool stay = false;
  if ((X <= Z && Z <= Y) || (Y <= Z && Z <= X)) {
    stay = true;
  }

  if (stay) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }
  return 0;
}