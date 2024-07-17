#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>
#include <deque>
#include <stack>
#include <set>
#include <bitset>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> v(N, 0);
  for (int i = 0; i < N; ++i) {
    int tmp;
    std::cin >> tmp;

    v[i] = tmp-1;
  }

  std::vector<std::pair<int, int>> memo;
  for (int i = 0; i < N; ++i) {
    while (i != v[i]) {
      memo.emplace_back(i, v[i]);
      std::swap(v[i], v[v[i]]);
    }
  }

  std::cout << memo.size() << std::endl;
  for (auto p: memo) {
    if (p.first > p.second) {
      std::swap(p.first, p.second);
    }
    std::cout << p.first+1 << ' ' << p.second+1 << std::endl;
  }
  return 0;
}