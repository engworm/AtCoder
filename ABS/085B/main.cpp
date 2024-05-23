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

  std::vector<int> d(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> d[i];
  }

  std::sort(d.begin(), d.end(), [] (int &x, int &y) {return x > y;});

  auto itr = std::unique(d.begin(), d.end());
  d.erase(itr, d.end());

  std::cout << d.size() << std::endl;

  return 0;
}