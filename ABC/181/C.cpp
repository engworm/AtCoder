#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;
  std::vector<std::pair<int, int>> vec(N, std::pair<int, int>(0, 0));
  for (auto &v : vec) {
    std::cin >> v.first;
    std::cin >> v.second;
  }

  return 0;
}