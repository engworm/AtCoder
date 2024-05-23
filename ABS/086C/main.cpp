#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

bool travel(int n, std::pair<int, int> X, std::pair<int, int> Y) {
  if (n == 0) {
    if (X == Y) return true;
    else return false;
  }

  std::pair<int, int> Z = X;
  Z.first += 1;
  bool b1 = travel(n-1, Z, Y);

  Z = X;
  Z.first -= 1;
  bool b2 = travel(n-1, Z, Y);

  Z = X;
  Z.second += 1;
  bool b3 = travel(n-1, Z, Y);

  Z = X;
  Z.second -= 1;
  bool b4 = travel(n-1, Z, Y);

  if (b1 || b2 || b3 || b4) return true;
  else return false;
}

int main() {
  int N;
  std::cin >> N;

  int *t = new int[N+1];
  t[0] = 0;
  std::pair<int, int> *X = new std::pair<int, int>[N];
  X[0].first = 0;
  X[0].second = 0;

  for (int i = 1; i < N+1; ++i) {
    std::cin >> t[i];
    std::cin >> X[i].first;
    std::cin >> X[i].second;
  }

  bool available = true;
  auto dis = [] (auto X, auto Y) {
    return std::abs(X.first - Y.first) + abs(X.second - Y.second);
  };

  for (int i = 1; i < N+1; ++i) {
    int dt = t[i] - t[i-1];
    if (!travel(dt, X[i], X[i-1]) || (dt < dis(X[i], X[i-1]))) {
      available = false;
      break;
    }
  }

  if (available) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}