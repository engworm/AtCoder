#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<std::vector<char>> S(8, std::vector<char>(8));
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      std::cin >> S[i][j];
    }
  }

  char f = 'a';
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (S[i][j] == '*') std::cout << char(f+j) << 8-i << std::endl;
    }
  }
  return 0;
}