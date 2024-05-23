#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int N, A, B;
  std::cin >> N >> A >> B;

  int r = 0;
  auto pop_maxdigit = [] (int x, int d) -> int {return x/std::pow(10, d);};
  for (int n = 1; n <= N; ++n) {
    // std::cout << "n=" << n << std::endl;

    int s = n;
    int total_digit = 0;
    for (int d = 4; d >= 0; --d) {
      // std::cout << "s=" << s << ", pop_maxdigit=" << pop_maxdigit(s, d) << std::endl;
      if (s == 0) break; 

      else {
        int md = pop_maxdigit(s, d);
        total_digit += md;
        s -= md*pow(10, d);
      }
    }

    // std::cout << "total_digit=" << total_digit << std::endl;

    if (A <= total_digit && total_digit <= B) {
      r += n;
    }
  }

  std::cout << r << std::endl;

  return 0;
}