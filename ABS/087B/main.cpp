#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int a, b, c, total;
  std::cin >> a >> b >> c >> total;

  int count = 0;
  for (int i = 0; i <= a; ++i) {
    int s1 = 500*i;

    for (int j = 0; j <= b; ++j) {
      int s2 = 100*j;

      for (int k = 0; k <= c; ++k) {
        int s3 = 50*k;

        if (s1 + s2 + s3 == total) count++;

      }
    }

  }

  std::cout << count << std::endl;

  return 0;
}