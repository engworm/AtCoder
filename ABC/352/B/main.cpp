#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  int checked = -1;
  for (int i = 0; i < S.length(); ++i) {
    // std::cout << "i: " << i << std::endl;

    int find_it = -1;
    for (int j = checked+1; j < T.length(); ++j) {
      if (S[i] == T[j]) {
        find_it = j;
        // std::cout << "find_it: " << j << std::endl; 
        std::cout << j+1 << ' ';
        break;
      }
    }
    checked = find_it;
    // std::cout << "checked: " << checked << std::endl;
  }
  std::cout << std::endl;

  return 0;
}