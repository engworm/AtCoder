#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>

int main() {

  int N;
  std::cin >> N;
  std::vector<int> h(N, -1);
  for (int n = 0; n < N; ++n) std::cin >> h[n];

  std::vector<int> effort(N, std::pow(10, 9));

  effort[0] = 0;
  effort[1] = std::abs(h[1] - h[0]);

  for (int loc = 2; loc < N; ++loc) {
    effort[loc] = [&] () -> int {
      if ((effort[loc-1]+std::abs(h[loc]-h[loc-1])) > (effort[loc-2]+std::abs(h[loc]-h[loc-2]))) 
        return effort[loc-2]+std::abs(h[loc]-h[loc-2]);
      else return effort[loc-1]+std::abs(h[loc]-h[loc-1]);
    }();
  }

  int min_effort = effort[N-1];
  std::cout << min_effort << std::endl;

  return 0;
}