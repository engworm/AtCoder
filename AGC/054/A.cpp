#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool check(const std::string &s) {
  bool b = false;
  if (s.front() != s.back()) {
    b = true;
  }
  return b;
}

int main() {
  int N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  std::vector<int> memo(N, 0);
  for (int i = 0; i < N; ++i) {
    std::string part_S = S.substr(0, N-i);
    if (check(part_S)) memo[N-i] += 1;
  }

  return 0;
}