#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int N;
  std::cin >> N;

  std::vector<int> v(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> v[i];
  }

  // std::for_each(v.begin(), v.end(), [] (int x) {
    // std::cout << x << std::endl;
  // });

  std::sort(v.begin(), v.end(), [](int a, int b) {return a > b;});

  // std::for_each(v.begin(), v.end(), [] (int x) {
    // std::cout << x << std::endl;
  // });

  int alice = 0;
  int bob = 0;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      alice += v[i];
    }
    else {
      bob += v[i];
    }
    // std::cout << alice << ' ' << bob << std::endl;
  }

  std::cout << alice - bob << std::endl;
  return 0;
}