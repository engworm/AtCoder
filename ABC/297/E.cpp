#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int N, K;
  std::cin >> N >> K;
  std::vector<std::vector<int>> table(N, std::vector<int>(0));
  for (auto &v : table) {
    std::cin >> v[0];
  }

  for (int i = 0; i < N; ++i) {
    std::cout << table[i][0] << std::endl;
  }

  return 0;
}