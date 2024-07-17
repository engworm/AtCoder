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

long long intersection_max(long long l1, long long r1, long long l2, long long r2) {
  long long tmp;
  for (long long ll = r1; ll >= l1; --ll) {
    if (l2 <= ll) {
      tmp = ll;
      break;
    }
  }
  return tmp;
}

int main() {
  int N;
  std::cin >> N;

  std::vector<long long> L(N), R(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> L[i] >> R[i];
  }

  bool hantei = false;
  long long left = 0, right = 0;

  for (int i = 0 ; i < N; ++i) {
    left += L[i];
    right += R[i];
  }

  if (left <= 0 && 0 <= right) {
    hantei = true;
  }

  if (!hantei) {
    std::cout << "No" << std::endl;
  }
  else {
    std::vector<long long> LL(N), RR(N);
    LL[N-1] = 0;
    RR[N-1] = 0;

    for (int i = N-1; i > 0; --i) {
      LL[i-1] = LL[i] - R[i];
      RR[i-1] = RR[i] - L[i];
      std::cout << LL[i-1] << ' ' << RR[i-1] << std::endl;
    }


    std::cout << "Yes" << std::endl;

    RR[0] = intersection_max(L[0], R[0], LL[0], RR[0]);
    std::cout << RR[0] << ' ';
    for (int i = 0; i < N; ++i) {
      std::cout << i << ": " << LL[i] << ' ' << RR[i] <<std::endl;
    }
    for (int i = N-1; i > 0; --i) {
      LL[i-1] = LL[i] - R[i];
      RR[i-1] = RR[i] - L[i];
      std::cout << LL[i-1] << ' ' << RR[i-1] << std::endl;
    }
    for (int i = 1; i < N; ++i) {
      std::cout << RR[i] - RR[i-1] << ' ';
    }
    std::cout << std::endl;

  }

  return 0;
}