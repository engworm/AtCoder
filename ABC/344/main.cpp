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
  std::vector<int> A(N, -1);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  int M;
  std::cin >> M;
  std::vector<int> B(M, -1);
  for (int i = 0; i < M; ++i) {
    std::cin >> B[i];
  }

  int L;
  std::cin >> L;
  std::vector<int> C(L, -1);
  for (int i = 0; i < L; ++i) {
    std::cin >> C[i];
  }

  int Q;
  std::cin >> Q;
  std::vector<long long> X(Q, -1);
  for (int i = 0; i < Q; ++i) {
    std::cin >> X[i];
  }

  std::set<int> s;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      for (int k = 0; k < L; ++k) {
        s.insert(A[i]+B[j]+C[k]);
      }
    }
  }


  for (int i = 0; i < Q; ++i) {
    if (s.contains(X[i])) {
      std::cout << "Yes" << std::endl;
    }
    else {
      std::cout << "No" << std::endl;
    }
  }
  return 0;
}