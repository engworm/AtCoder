#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  int D;
  std::cin >> D;

  std::vector<int> T(N);
  for (auto &t : T) {
    std::cin >> t;
  }

  double dif;
  double t = -1;
  for (int i = 0; i < N-1; ++i) {
    dif = T[i+1] - T[i];
    if (dif <= D) {
      t = i+1;
      break;
    } 
  }

  if (t != -1) std::cout << T[t] << std::endl;
  else std::cout << -1 << std::endl;

  return 0;
}