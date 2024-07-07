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
  int N, K, X;
  std::cin >> N >> K >> X;

  std::vector<int> A(N+1, 0);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  auto it = A.begin();
  A.insert(it + K, X);

  for (int i = 0; i < N+1; ++i) {
    std::cout << A[i] << ' ';
  }
  std::cout << std::endl;
  return 0;
}