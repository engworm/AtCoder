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

  std::vector<long long> A(N);
  std::vector<long long> B(N);

  for (int i = 0; i < 2*N; ++i) {
    if (i%2 == 0) {
      std::cin >> A[i/2];
    }
    else {
      std::cin >> B[i/2];
    }
  }


  std::vector<long long> D(N);
  for (int i = 0; i < N; ++i) {
    D[i] = B[i] - A[i];
  }

  std::sort(D.begin(), D.end(), [](int x, int y) {return x > y;});

  // std::for_each(D.begin(), D.end(), [](int x) {std::cout << x << std::endl;});

  long long sum = std::accumulate(A.begin(), A.end(), (long long)0);
  sum += D[0];

  std::cout << sum << std::endl;

  return 0;
}