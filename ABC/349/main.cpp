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
  std::string S;
  std::string T;
  std::cin >> S >> T;

  int idx = 0;
  for (int i = 0; i < S.length(); ++i) {
    if (std::toupper(S.at(i)) == T[idx]) {
      idx++;
    }
  }

  // std::cout << "idx: " << idx << std::endl;

  if (idx == 3 || (idx == 2 && T.at(2) == 'X')) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}