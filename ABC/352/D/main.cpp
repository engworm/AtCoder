#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> P[i];
  }

  std::vector<int> sorted_P = P;
  std::sort(sorted_P.begin(), sorted_P.end());


  int min = 1000000;
  for (int i = 0; i <= N-K; ++i) {
    if (sorted_P[i+K-1] - sorted_P[i] == K-1) {

      int min_idx = K;
      int max_idx = -1;
      for (int j = 0; j < K; ++j) {
        auto itr = std::find(P.begin(), P.end(), sorted_P[i+j]);
        int idx = std::distance(P.begin(), itr);
        if (idx < min_idx) min_idx = idx;
        if (idx > max_idx) max_idx = idx;
      }

      int tmp = max_idx - min_idx;
      if (tmp < min) min = tmp;
      // std::cout << "idx1: " << idx_vector[0] << " idx2: " << idx_vector[K-1] << std::endl;
    }
  }

  std::cout << min << std::endl;
  return 0;
}