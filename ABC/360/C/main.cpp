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

int main() {
  int N;
  std::cin >> N;

  std::vector<int> A(N, 0);
  std::vector<int> W(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
    A[i] -= 1;
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> W[i];
  }

  std::vector<std::vector<int>> v(N, std::vector<int>(0));

  for (int i = 0; i < N; ++i) {
    v[A[i]].push_back(W[i]);
  }

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    if (v[i].size() >= 2) {
      std::sort(v[i].rbegin(), v[i].rend());
      sum += std::accumulate(v[i].begin()+1, v[i].end(), int{0});
    }
  }

  std::cout << sum << std::endl;

  return 0;
}