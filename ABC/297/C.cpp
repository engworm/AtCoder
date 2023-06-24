#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int H, W;
  std::cin >> H >> W;

  std::vector<std::string> S(H);
  for (int i = 0; i < H; ++i) std::cin >> S[i];


  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (S[i][j] == 'T' && S[i][j+1] == 'T') {
        S[i][j] = 'P'; 
        S[i][j+1] = 'C';
      }
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cout << S[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}