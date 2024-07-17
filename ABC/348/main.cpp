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
#include <map>

int main() {
  int N;
  std::cin >> N;

  std::map<int, int> m;
  for (int i = 0; i < N; ++i) {
    int a, c;
    std::cin >> a >> c;

    if (m.contains(c)) {
      m.at(c) = std::min(m.at(c), a);
    }
    else {
      m.emplace(c, a);
    }
  }

  int max_min = 0;
  std::for_each(m.begin(), m.end(), [&max_min] (const std::pair<int, int> &x) {
    max_min = std::max(max_min, x.second);
  });

  std::cout << max_min << std::endl;

  return 0;
}