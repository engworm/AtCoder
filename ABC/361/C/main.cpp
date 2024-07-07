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
  int N, K;
  std::cin >> N >> K;

  std::vector<int> A(N, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  std::sort(A.begin(), A.end());


  // for (int i = 0; i < N; ++i) {
    // std::cout << A[i] << ' ';
  // }
  // std::cout << std::endl;

  auto max = A.end() - 1;
  auto min = A.begin();

  int min_score = *max - *min;

  for (int i = 0; i < K; ++i) {
    // 末尾を消す場合
    auto tmp_max = A.end() - 2;
    min = A.begin();

    int tmp1 = *tmp_max - *min;

    // 先頭を消す場合
    max = A.end() - 1;
    auto tmp_min = A.begin() + 1;

    int tmp2 = *max - *tmp_min;

    if (tmp1 < tmp2) {
      min_score = tmp1;
      A.erase(max);
    }
    else {
      min_score = tmp2;
      A.erase(min);
    }


    // std::cout << "i: " << i << std::endl;
    // for (auto a: A) {
      // std::cout << a << ' ';
    // }
    // std::cout << std::endl;

    // std::cout << "score" << min_score << std::endl;
  }

  std::cout << min_score << std::endl;

  return 0;
}