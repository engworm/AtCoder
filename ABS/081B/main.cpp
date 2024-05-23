#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int count_even(int x, int c) {
  if (x % 2 != 0 || x == 0) {
    return c;
  }
  return count_even(x/2, c+1);
}

int main() {
  int N;
  std::cin >> N;

  int *A = new int[N];
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }

  int r = 100;
  auto min = [] (int x, int y) -> int {return (x > y)? y : x;};
  for (int i = 0; i < N; ++i) {
    r = min(r, count_even(A[i], 0));
  }

  std::cout << r << std::endl;

  delete[] A;

  return 0;
}