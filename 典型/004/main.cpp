#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <deque>
#include <cmath>
#include <numeric>

int main() {
  int H, W;
  std::cin >> H >> W;

  int **A = new int*[H];
  for (int i = 0; i < H; ++i) {
    A[i] = new int[W];
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cin >> A[i][j]; 
    }
  }

  int *yoko = new int[H];
  int *tate = new int[W];

  int tmp;
  for (int i = 0; i < H; ++i) {
    tmp = 0;
    for (int j = 0; j < W; ++j) {
      tmp += A[i][j];
    }
    yoko[i] = tmp;
  }

  for (int j = 0; j < W; ++j) {
    tmp = 0;
    for (int i = 0; i < H; ++i) {
      tmp += A[i][j];
    }
    tate[j] = tmp;
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      std::cout << yoko[i] + tate[j] - A[i][j] << ' ';
    }
    std::cout << std::endl;
  }
  return 0;
}