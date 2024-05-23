#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>
#include <bitset>

int main() {
  int N;
  std::cin >> N;

  if (N % 2 == 0) {

    for (int i = 0; i < (1 << (N-2)); ++i) {

      std::bitset<20> bit(2*i);

      bit.set(0, 1);
      bit.set(N-1, 0);

      // std::cout << "bit=" << bit << std::endl;

      int c = 0;
      bool priority = true;
      for (int j = 0; j < N; ++j) {
        if (bit.test(j)) c += 1;
        else c -= 1;

        if (c < 0) {
          priority = false;
          break;
        }
      }

      // std::cout << c << ' ' << priority << std::endl;

      if (c == 0 && priority) {
        std::string s = "";
        for (int j = N-1; j >= 0; --j) {
          if (bit.test(j)) {
            s += ")";
          }
          else {
            s += "(";
          }
        }

        std::cout << s << std::endl;
      }
    }
  }

  return 0;
}