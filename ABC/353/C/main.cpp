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
  const int M = 1e8;

  int N;
  std::cin >> N;

  std::vector<long long> A(N, 0);
  for (long long i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  long long S1 = 0;
  for (long long i = 0; i < N-1; ++i) {
    S1 += (i+1)*A[N-i-2];
  }

  // std::cout << "S1: " << S1 << std::endl;

  std::vector<long long> memo(N, 0);
  memo.at(0) = A.at(N-1);
  for (int i = 0; i < N-2; ++i) {
    memo.at(i+1) = A.at(N-i-2) + memo.at(i);
  }

  long long S2 = std::accumulate(memo.begin(), memo.end(), 0);
  // std::cout << "S2: " << S2 << std::endl;

  std::sort(A.begin(), A.end());

  int lidx = 0;
  int ridx = N-1;
  int c = 0;
  for (int i = 0; i < N-1; ++i) {
    lidx = i;

    // if (lidx >= ridx) {
      // c += N-lidx-1;
      // continue;
    // }

    long long x = A.at(lidx);
    while (x + A.at(ridx) >= M && 0 <= ridx) {
      ridx--;
    }

    // std::cout << "lidx: " << lidx << std::endl;
    // std::cout << "ridx: " << ridx << std::endl;

    c += N-std::max(ridx,lidx)-1;
    // std::cout << "detect: " << N-std::max(ridx,lidx)-1 << std::endl;
  }

  // std::cout << "over: " << c << std::endl;

  long long S3 = S1 + S2;
  long long D = c*M;
  std::cout << S3 - D << std::endl;
  return 0;
}